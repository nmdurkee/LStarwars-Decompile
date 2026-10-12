/* Ghidra analysis pseudocode, not original source.
 * ev_84e2b506f29363daa42df6f934b4c92b1585b3e8a57a6b6866ee0e5470757f5b
 * Entry: 0x516850; label: FUN_00516850
 */

undefined4
FUN_00516850(int param_1,undefined4 param_2,int param_3,undefined4 *param_4,int param_5,int param_6)

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
    if (DAT_009238cc != (code *)0x0) {
      fVar3 = (float10)(*DAT_009238cc)((int)**(short **)(iVar2 + 0x50));
      *(float *)(*(int *)(param_3 + 0xd0) + 0x234) = (float)fVar3;
      goto LAB_005168c9;
    }
    uVar1 = 0x3f800000;
  }
  else {
    uVar1 = *(undefined4 *)
             ((uint)*(byte *)(param_3 + 0x138) * 0xa4 + 0x98 + *(int *)(param_1 + 0x18));
  }
  *(undefined4 *)(iVar2 + 0x234) = uVar1;
LAB_005168c9:
  if ((param_5 != 0) && (iVar2 = FUN_004f8b10(*param_4,"default"), iVar2 != 0)) {
    fVar3 = (float10)FUN_00514920(param_3,param_2,*param_4);
    *(float *)(*(int *)(param_3 + 0xd0) + 0x234) = (float)fVar3;
  }
  return 1;
}

