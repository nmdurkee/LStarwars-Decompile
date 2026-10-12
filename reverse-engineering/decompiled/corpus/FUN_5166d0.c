/* Ghidra analysis pseudocode, not original source.
 * ev_84e2b506f29363daa42df6f934b4c92b1585b3e8a57a6b6866ee0e5470757f5b
 * Entry: 0x5166d0; label: FUN_005166d0
 */

undefined4
FUN_005166d0(int param_1,undefined4 param_2,int param_3,undefined4 *param_4,int param_5,int param_6)

{
  undefined4 uVar1;
  int iVar2;
  float10 fVar3;
  
  if (param_3 == 0) {
    return 1;
  }
  iVar2 = *(int *)(param_3 + 0xd0);
  if (iVar2 == 0) {
    return 1;
  }
  if (param_6 == 0) {
    return 1;
  }
  if (*(byte *)(param_3 + 0x138) == 0xff) {
    if (DAT_009238d4 != (code *)0x0) {
      fVar3 = (float10)(*DAT_009238d4)((int)**(short **)(iVar2 + 0x50));
      *(float *)(*(int *)(param_3 + 0xd0) + 0x23c) = (float)fVar3;
      goto LAB_00516749;
    }
    uVar1 = 0x3f800000;
  }
  else {
    uVar1 = *(undefined4 *)
             ((uint)*(byte *)(param_3 + 0x138) * 0xa4 + 0xa0 + *(int *)(param_1 + 0x18));
  }
  *(undefined4 *)(iVar2 + 0x23c) = uVar1;
LAB_00516749:
  if ((param_5 != 0) && (iVar2 = FUN_004f8b10(*param_4,"default"), iVar2 != 0)) {
    fVar3 = (float10)FUN_00514920(param_3,param_2,*param_4);
    *(float *)(*(int *)(param_3 + 0xd0) + 0x23c) = (float)fVar3;
  }
  return 1;
}

