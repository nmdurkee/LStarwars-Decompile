/* Ghidra analysis pseudocode, not original source.
 * ev_b9f25343996aedf2297d7d3ade291ed602d662c61207b78e5aec6bfbfbdc583f
 * Entry: 0x69b2e0; label: FUN_0069b2e0
 */

undefined4 FUN_0069b2e0(int param_1,int param_2)

{
  int *in_EAX;
  int iVar1;
  
  if (*in_EAX == 0) {
    return 0xffffff7f;
  }
  if ((code *)in_EAX[0xb1] != (code *)0x0) {
    iVar1 = (*(code *)in_EAX[0xb1])(*in_EAX,param_1,param_2,0);
    if (iVar1 != -1) {
      in_EAX[2] = param_1;
      in_EAX[3] = param_2;
      FUN_0069fae0(in_EAX + 6);
      return 0;
    }
  }
  return 0xffffff80;
}

