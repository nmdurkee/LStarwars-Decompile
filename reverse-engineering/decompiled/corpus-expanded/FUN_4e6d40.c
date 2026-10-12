/* Ghidra pseudocode, not original source.
 * ev_82279d4937da693375712195ef93cdd3155885c4c37192da562bbaf9be35e879
 * Entry: 0x4e6d40; label: FUN_004e6d40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e6d40(int param_1)

{
  float fVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_40 [16];
  
  if ((((*(char *)(param_1 + 0x280) == '\0') || (*(char *)(param_1 + 0x280) == '\x01')) &&
      (*(short *)(param_1 + 0x1064) == DAT_007f19a4)) &&
     (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x127e) != '\0')) {
    if (*(int *)(*(int *)(param_1 + 0x50) + 0x24) != 0) {
      puVar4 = (undefined4 *)(param_1 + 0x904);
      puVar5 = local_40;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x1270,local_40);
    }
    puVar2 = PTR_DAT_00802c54;
    fVar1 = _DAT_00925018 / 5.0;
    *(float *)(&DAT_0088a534 + *(char *)(param_1 + 0x280) * 4) =
         *(float *)(&DAT_0088a534 + *(char *)(param_1 + 0x280) * 4) + fVar1;
    if (1.0 < *(float *)(&DAT_0088a534 + *(char *)(param_1 + 0x280) * 4)) {
      *(float *)(&DAT_0088a534 + *(char *)(param_1 + 0x280) * 4) =
           *(float *)(&DAT_0088a534 + *(char *)(param_1 + 0x280) * 4) - 1.0;
    }
    *(float *)(&DAT_0088a53c + *(char *)(param_1 + 0x280) * 4) =
         *(float *)(&DAT_0088a53c + *(char *)(param_1 + 0x280) * 4) + fVar1;
    if (1.0 < *(float *)(&DAT_0088a53c + *(char *)(param_1 + 0x280) * 4)) {
      *(float *)(&DAT_0088a53c + *(char *)(param_1 + 0x280) * 4) =
           *(float *)(&DAT_0088a53c + *(char *)(param_1 + 0x280) * 4) - 1.0;
    }
    if (*(int *)(*(int *)(param_1 + 0x50) + 0x28) != 0) {
      puVar4 = (undefined4 *)(param_1 + 0x944);
      puVar5 = local_40;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      FUN_005f33b0(*(int *)(puVar2 + 0x2ac0) + 0x1270,local_40);
    }
    fVar1 = _DAT_00925018 / 5.0;
    *(float *)(&DAT_00800214 + *(char *)(param_1 + 0x280) * 4) =
         *(float *)(&DAT_00800214 + *(char *)(param_1 + 0x280) * 4) + fVar1;
    if (1.0 < *(float *)(&DAT_00800214 + *(char *)(param_1 + 0x280) * 4)) {
      *(float *)(&DAT_00800214 + *(char *)(param_1 + 0x280) * 4) =
           *(float *)(&DAT_00800214 + *(char *)(param_1 + 0x280) * 4) - 1.0;
    }
    *(float *)(&DAT_0080021c + *(char *)(param_1 + 0x280) * 4) =
         *(float *)(&DAT_0080021c + *(char *)(param_1 + 0x280) * 4) + fVar1;
    if (1.0 < *(float *)(&DAT_0080021c + *(char *)(param_1 + 0x280) * 4)) {
      *(float *)(&DAT_0080021c + *(char *)(param_1 + 0x280) * 4) =
           *(float *)(&DAT_0080021c + *(char *)(param_1 + 0x280) * 4) - 1.0;
      return;
    }
  }
  return;
}

