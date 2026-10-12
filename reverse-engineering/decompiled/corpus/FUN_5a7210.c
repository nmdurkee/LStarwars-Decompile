/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a7210; label: FUN_005a7210
 */

void FUN_005a7210(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puStack_10;
  int iStack_c;
  int iStack_8;
  
  if (param_3 != (undefined4 *)0x0) {
    param_3[1] = 0;
    puStack_10 = param_3 + 3;
    *param_3 = 0xffffffff;
    param_3[2] = 0;
    FUN_004ef6e0(puStack_10,0,0);
    if (((param_1 != 0) && (*(int *)(param_1 + 0x46bc) != 0)) &&
       (iStack_c = 0, 0 < *(int *)(param_1 + 0x46c0))) {
      iVar8 = *(int *)(param_1 + 0x46bc) + 0x24;
      do {
        if (0xf < iStack_c) {
          return;
        }
        uVar6 = 1 << ((byte)iStack_c & 0x1f);
        iVar5 = (int)(iStack_c + (iStack_c >> 0x1f & 0x1fU)) >> 5;
        if ((*(uint *)(iVar8 + 0xa4) & 0x40000) == 0) {
          param_3[iVar5] = param_3[iVar5] & ~uVar6;
        }
        if ((*(uint *)(iVar8 + 0xa4) & 0x2000000) != 0) {
          param_3[iVar5 + 1] = param_3[iVar5 + 1] | uVar6;
        }
        iVar2 = FUN_005cfac0(iVar8);
        if (iVar2 == 0) {
          *puStack_10 = DAT_0093b0cc;
          puStack_10[1] = DAT_0093b0d0;
          puStack_10[2] = DAT_0093b0d4;
        }
        else {
          iVar2 = FUN_005d0370(iVar8);
          *puStack_10 = *(undefined4 *)(iVar2 + 0x30);
          puStack_10[1] = *(undefined4 *)(iVar2 + 0x34);
          puStack_10[2] = *(undefined4 *)(iVar2 + 0x38);
        }
        iStack_8 = 0;
        if (*(char *)(iVar8 + 0xad) != '\0') {
          iVar2 = iVar8 + 0x38;
          puVar1 = puStack_10;
          do {
            puVar7 = puVar1 + 0x30;
            if (iVar2 != 0) {
              iVar3 = FUN_005cfac0(iVar2);
              if (iVar3 == 0) {
                *puVar7 = DAT_0093b0cc;
                puVar1[0x31] = DAT_0093b0d0;
                uVar4 = DAT_0093b0d4;
              }
              else {
                iVar3 = FUN_005d0370(iVar2);
                *puVar7 = *(undefined4 *)(iVar3 + 0x30);
                puVar1[0x31] = *(undefined4 *)(iVar3 + 0x34);
                uVar4 = *(undefined4 *)(iVar3 + 0x38);
              }
              puVar1[0x32] = uVar4;
            }
            iStack_8 = iStack_8 + 1;
            iVar2 = iVar2 + 0xc;
            puVar1 = puVar7;
          } while (iStack_8 < (int)(uint)*(byte *)(iVar8 + 0xad));
        }
        param_3[iVar5 + 2] = param_3[iVar5 + 2] | uVar6;
        iStack_c = iStack_c + 1;
        puStack_10 = puStack_10 + 3;
        iVar8 = iVar8 + 0xd4;
      } while (iStack_c < *(int *)(param_1 + 0x46c0));
    }
  }
  return;
}

