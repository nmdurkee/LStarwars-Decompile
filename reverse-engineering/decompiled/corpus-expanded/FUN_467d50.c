/* Ghidra pseudocode, not original source.
 * ev_fb4a243913288e8884e4b26b9d3f1b2cc90d3774ba2cd7b272b490162dad9d99
 * Entry: 0x467d50; label: FUN_00467d50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00467d50(undefined4 param_1,int *param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint *puVar7;
  
  FUN_00467cd0(param_1,param_3);
  if (param_3 != 0) {
    iVar5 = 0;
    if (*(short *)((int)param_2 + 0xe) != 0) {
      puVar7 = (uint *)(*param_2 + 0xa0);
      do {
        if (0x7f < iVar5) break;
        iVar2 = (int)(iVar5 + (iVar5 >> 0x1f & 0x1fU)) >> 5;
        uVar4 = 1 << ((byte)iVar5 & 0x1f);
        if ((*puVar7 & 2) == 0) {
          puVar1 = (uint *)(param_3 + 0x10 + iVar2 * 4);
          *puVar1 = *puVar1 & ~uVar4;
        }
        if ((*puVar7 & 1) == 0) {
          puVar1 = (uint *)(param_3 + iVar2 * 4);
          *puVar1 = *puVar1 & ~uVar4;
        }
        if ((*puVar7 & 0x200) != 0) {
          puVar1 = (uint *)(param_3 + 0x20 + iVar2 * 4);
          *puVar1 = *puVar1 | uVar4;
        }
        if ((*puVar7 & 0x800) != 0) {
          puVar1 = (uint *)(param_3 + 0x30 + iVar2 * 4);
          *puVar1 = *puVar1 | uVar4;
        }
        if ((*puVar7 & 0x4000) != 0) {
          puVar1 = (uint *)(param_3 + 0x40 + iVar2 * 4);
          *puVar1 = *puVar1 | uVar4;
        }
        if ((*puVar7 & 0x8000) != 0) {
          puVar1 = (uint *)(param_3 + 0x50 + iVar2 * 4);
          *puVar1 = *puVar1 | uVar4;
        }
        if ((*puVar7 & 0x10000) != 0) {
          puVar1 = (uint *)(param_3 + 0x60 + iVar2 * 4);
          *puVar1 = *puVar1 | uVar4;
        }
        iVar5 = iVar5 + 1;
        puVar7 = puVar7 + 0x29;
      } while (iVar5 < (int)(uint)*(ushort *)((int)param_2 + 0xe));
    }
    param_3 = param_3 + 0x70;
    piVar6 = param_2 + 6;
    iVar5 = 8;
    do {
      iVar2 = 0;
      do {
        if (iVar2 < (int)(uint)*(byte *)((int)piVar6 + 0x26)) {
          iVar3 = piVar6[iVar2] - *param_2;
          *(char *)(param_3 + iVar2) =
               ((char)(iVar3 / 0xa4) + (char)(iVar3 >> 0x1f)) -
               (char)((longlong)iVar3 * 0x63e7063f >> 0x3f);
        }
        else {
          *(undefined1 *)(param_3 + iVar2) = 0xff;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 8);
      param_3 = param_3 + 8;
      piVar6 = piVar6 + 10;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return;
}

