/* Ghidra analysis pseudocode, not original source.
 * ev_c738a20aab8983fc200bedf50414a33a26b9029d211323cd468d6edebc3fc3e7
 * Entry: 0x553610; label: FUN_00553610
 */

void FUN_00553610(int *param_1,float param_2)

{
  float *pfVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_40 [16];
  
  iVar2 = FUN_005cfac0(param_1);
  if (iVar2 != 0) {
    FUN_0054fa00();
    puVar3 = (undefined4 *)FUN_005d0420(param_1);
    if ((puVar3 != (undefined4 *)0x0) &&
       (*(int *)(*(int *)(*param_1 + 0x54) + (uint)*(ushort *)(puVar3 + 0x17) * 4) != 0)) {
      pfVar1 = *(float **)(*(int *)(*param_1 + 0x54) + (uint)*(ushort *)(puVar3 + 0x17) * 4);
      if (param_2 == 1e+09) {
        param_2 = *pfVar1;
      }
      if ((!NAN(param_2) && 1.0 < param_2 != (param_2 == 1.0)) && (param_2 <= *pfVar1)) {
        if (pfVar1 != (float *)0x0) {
          FUN_005f3390(pfVar1,0,param_2,local_40);
        }
        puVar4 = local_40;
        puVar5 = puVar3;
        for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        iVar2 = FUN_005d0370(param_1);
        puVar3[0xc] = *(undefined4 *)(iVar2 + 0x30);
        puVar3[0xd] = *(undefined4 *)(iVar2 + 0x34);
        puVar3[0xe] = *(undefined4 *)(iVar2 + 0x38);
        puVar3[0x13] = param_2;
        return;
      }
    }
  }
  return;
}

