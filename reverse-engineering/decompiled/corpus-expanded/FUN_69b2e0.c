/* Ghidra pseudocode, not original source.
 * ev_4cbe307265f31e413c5f7cc9b7da0764bbafe6907e0e37f5fb37c4e62049af07
 * Entry: 0x69b2e0; label: FUN_0069b2e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

