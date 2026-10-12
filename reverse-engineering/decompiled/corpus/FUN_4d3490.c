/* Ghidra analysis pseudocode, not original source.
 * ev_a7e7d672623d9c9895986762e49f541fc5bec923712a30ebf66db24116e2b0d4
 * Entry: 0x4d3490; label: FUN_004d3490
 */

void FUN_004d3490(float param_1)

{
  int iVar1;
  float10 fVar2;
  double local_18;
  float local_10;
  undefined1 local_c [12];
  
  if ((*(int *)((int)param_1 + 4) != 0) &&
     (iVar1 = *(int *)(*(int *)((int)param_1 + 4) + 0xcc4), iVar1 != 0)) {
    FUN_004d2c40(param_1,iVar1);
    if (*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 0xcc4) + 0x84) != 0) {
      iVar1 = FUN_004d2430();
      if (iVar1 != 0) {
        FUN_005b3800(local_c,iVar1,(int)param_1 + 0x88);
        local_18 = (double)param_1;
        fVar2 = (float10)FUN_005b3b00(local_c);
        if (fVar2 < (float10)local_18 * (float10)local_18) {
          FUN_00580120(param_1,1);
        }
      }
    }
    if (((*(float *)((int)param_1 + 0xd0) < *(float *)((int)param_1 + 200) !=
          (*(float *)((int)param_1 + 0xd0) == *(float *)((int)param_1 + 200))) &&
        (iVar1 = *(int *)(*(int *)((int)param_1 + 4) + 0xcc4), iVar1 != 0)) &&
       ((*(byte *)(iVar1 + 1) & 8) != 0)) {
      local_18 = 0.0;
      local_10 = *(float *)((int)param_1 + 0xd8) + *(float *)((int)param_1 + 0xd8);
      FUN_005b3200(&local_18,&local_18,(int)param_1 + 8);
      FUN_005b3800(local_c,(int)param_1 + 0x88,&local_18);
      iVar1 = FUN_00582270(param_1,local_c,(int)param_1 + 0x108,(int)param_1 + 0x114,
                           *(undefined4 *)((int)param_1 + 0xd8),0);
      if (iVar1 == 0) {
        FUN_004d2f90(param_1,*(undefined4 *)(*(int *)((int)param_1 + 4) + 0xcc4));
      }
    }
  }
  return;
}

