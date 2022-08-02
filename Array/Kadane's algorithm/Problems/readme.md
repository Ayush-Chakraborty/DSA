# Problem List

🚀 Max Product Subarray 👉 [InterviewBit](https://www.interviewbit.com/problems/max-product-subarray/)<details><summary>Approach</summary>
1. For any index $i$ maximum product can be achieved from prev *min product subarray* (if $a[i]<0$) or from *max product subarray* (if $a[i]>=0$)
2. So for any index $i$ **Minimum:** $mn=min(a[i],mn*a[i],mx*a[i])$
3. **Maximum:** $mx=max(a[i],mn*a[i],mx*a[i])$
</details>