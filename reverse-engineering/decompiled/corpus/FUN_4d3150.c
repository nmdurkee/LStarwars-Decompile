/* Ghidra analysis pseudocode, not original source.
 * ev_a7e7d672623d9c9895986762e49f541fc5bec923712a30ebf66db24116e2b0d4
 * Entry: 0x4d3150; label: FUN_004d3150
 */

void FUN_004d3150(float param_1)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  undefined1 local_c [12];
  
  if (((param_1 != 0.0) && (iVar1 = *(int *)((int)param_1 + 4), iVar1 != 0)) &&
     (*(int *)(iVar1 + 0xcc4) != 0)) {
    iVar1 = *(int *)(iVar1 + 0xcc4);
    if ((*(int *)(iVar1 + 0x84) != 0) && (iVar2 = FUN_004d2430(), iVar2 != 0)) {
      FUN_005b3800(local_c,iVar2,(int)param_1 + 0x88);
      fVar3 = (float10)FUN_005b3b00(local_c);
      if (fVar3 < (float10)param_1 * (float10)param_1) {
        FUN_004d2490(*(undefined1 *)(*(int *)(*(int *)((int)param_1 + 4) + 0xcc4) + 4));
      }
    }
    *(undefined1 *)(iVar1 + 1) = 1;
  }
  return;
}

