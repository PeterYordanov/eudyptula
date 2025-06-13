#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/textsearch.h>

#define MY_ID "7c1caf2f50d1"
static	struct ts_config *conf;

static unsigned int myhook(void *priv, struct sk_buff *skb,
                           const struct nf_hook_state *state)
{
       unsigned int pos;

       pos = skb_find_text(skb, 0, skb->len, conf);
       if (pos != UINT_MAX)
               pr_debug(MY_ID " at %d\n", pos);

	return NF_ACCEPT;
}

static struct nf_hook_ops euhooks =  {
	.hook = myhook,
	.hooknum = NF_INET_LOCAL_IN,
	.pf = NFPROTO_IPV4,
	.priority = NF_IP_PRI_FIRST
};

static int __init hello_init(void)
{
	pr_debug("Registering hook\n");

	conf = textsearch_prepare("kmp", MY_ID, 12, GFP_KERNEL, TS_AUTOLOAD);
	if (IS_ERR(conf))
		return PTR_ERR(conf);

       return nf_register_net_hook(&init_net, &euhooks);
}

static void __exit hello_exit(void)
{
	pr_debug("Unregistering hook\n");
	textsearch_destroy(conf);
       nf_unregister_net_hook(&init_net, &euhooks);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("7c1caf2f50d1");
MODULE_DESCRIPTION("netfilter module task 19");
