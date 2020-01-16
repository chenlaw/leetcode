ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int len1 = 0;
	int len2 = 0;
	ListNode *l = l1;
	while (l != NULL) {

		l = l->next;
		len1++;
	}
	l = l2;
	while (l != NULL) {

		l = l->next;
		len2++;
	}
	l = len1 >= len2 ? l1 : l2;
	ListNode* ll = len1 < len2 ? l1 : l2;
	int len = len1 > len2 ? len1 : len2;
	int jinwei = 0;
	for (int i = 0; i < len; i++) {
		int m = l->val + ll->val + jinwei;
		l->val = m % 10;
		jinwei = m / 10;

		if (l->next == NULL) {
			if (jinwei > 0)
				l->next = new ListNode(jinwei);
		}l = l->next;
		if (ll->next == NULL) {
			ll->val = 0;
		}
		else {
			ll = ll->next;

		}

	}
	return len1 >= len2 ? l1 : l2;
}
