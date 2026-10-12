/* Ghidra pseudocode, not original source.
 * ev_cd85811e73cbe502a6d015fc1f20588fa81ce6efb8852e42609516c9f2c20483
 * Entry: 0x5153c0; label: FUN_005153c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005153c0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  float10 fVar2;
  
  if ((param_3 != 0) && (*(int *)(param_3 + 0xe4) != 0)) {
    if (DAT_00923908 != (code *)0x0) {
      iVar1 = (*DAT_00923908)(param_1,param_3);
      if (iVar1 != 0) {
        fVar2 = (float10)FUN_005becc0(*(int *)(param_3 + 0xe4) + 0x5c,iVar1,0);
        return fVar2;
      }
    }
    if ((param_1 != 0) && (*(byte *)(param_3 + 0x138) != 0xff)) {
      fVar2 = (float10)FUN_005becc0(*(int *)(param_3 + 0xe4) + 0x5c,
                                    (uint)*(byte *)(param_3 + 0x138) * 0xa4 +
                                    *(int *)(param_1 + 0x18) + 0x20,0);
      return fVar2;
    }
  }
  return (float10)3.4028235e+38;
}

