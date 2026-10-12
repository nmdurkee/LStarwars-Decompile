/* Ghidra pseudocode, not original source.
 * ev_ea16e91579c763516a5ec9191881acc35a0dcfc8106f35e62baf3c19fc401ba6
 * Entry: 0x447030; label: FUN_00447030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00447030(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  bool bVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  iVar8 = 0;
  bVar5 = true;
  if (param_6 != 0) {
    if (((param_3 != 0) && (piVar7 = *(int **)(param_3 + 0xd0), piVar7 != (int *)0x0)) &&
       (*piVar7 != 0)) {
      iVar8 = *piVar7;
    }
    iVar9 = 0;
    if (0 < param_5) {
      do {
        iVar6 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"character");
        if (iVar6 == 0) {
          iVar6 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar9 * 4),"dont_check_terrain");
          if (iVar6 != 0) {
            bVar5 = false;
          }
        }
        else if ((DAT_00923904 == (code *)0x0) ||
                (piVar7 = (int *)(*DAT_00923904)(param_1,iVar6 + 10), piVar7 == (int *)0x0)) {
          iVar8 = 0;
        }
        else {
          iVar8 = *piVar7;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < param_5);
    }
    if (((iVar8 != 0) && ((*(uint *)(iVar8 + 0x1f8) & 0x400) != 0)) &&
       (*(byte *)(iVar8 + 0x400) != 0xff)) {
      iVar9 = (uint)*(byte *)(iVar8 + 0x400) * 0xa4 + *(int *)(param_1 + 0x18);
      *(undefined4 *)(iVar8 + 0x5c) = *(undefined4 *)(iVar9 + 0x20);
      *(undefined4 *)(iVar8 + 0x60) = *(undefined4 *)(iVar9 + 0x24);
      *(undefined4 *)(iVar8 + 100) = *(undefined4 *)(iVar9 + 0x28);
      *(undefined2 *)(iVar8 + 0x27a) = *(undefined2 *)(iVar9 + 0x2c);
      *(undefined2 *)(iVar8 + 0x58) = *(undefined2 *)(iVar9 + 0x2c);
      uVar1 = *(undefined2 *)(iVar9 + 0x2c);
      *(ushort *)(iVar8 + 0x42e) = *(ushort *)(iVar8 + 0x42e) & 0xfffe;
      *(undefined4 *)(iVar8 + 0x80) = *(undefined4 *)(iVar8 + 0x5c);
      *(undefined4 *)(iVar8 + 0x84) = *(undefined4 *)(iVar8 + 0x60);
      *(undefined2 *)(iVar8 + 0x5a) = uVar1;
      *(undefined4 *)(iVar8 + 0x88) = *(undefined4 *)(iVar8 + 100);
      *(undefined4 *)(iVar8 + 0x98) = *(undefined4 *)(iVar8 + 0x5c);
      _DAT_0093d620 = *(undefined4 *)(iVar8 + 0x80);
      *(undefined4 *)(iVar8 + 0x9c) = *(undefined4 *)(iVar8 + 0x60);
      *(undefined4 *)(iVar8 + 0xa0) = *(undefined4 *)(iVar8 + 100);
      DAT_0093d624 = *(undefined4 *)(iVar8 + 0x84);
      DAT_0093d628 = *(undefined4 *)(iVar8 + 0x88);
      *(undefined4 *)(iVar8 + 0x8c) = *(undefined4 *)(iVar8 + 0x80);
      uVar2 = *(undefined4 *)(iVar8 + 0x5c);
      *(undefined4 *)(iVar8 + 0x90) = *(undefined4 *)(iVar8 + 0x84);
      uVar3 = *(undefined4 *)(iVar8 + 0x60);
      *(undefined4 *)(iVar8 + 0x94) = *(undefined4 *)(iVar8 + 0x88);
      uVar4 = *(undefined4 *)(iVar8 + 100);
      *(undefined4 *)(iVar8 + 0x1cc) = uVar2;
      *(undefined4 *)(iVar8 + 0x1b4) = uVar2;
      *(undefined4 *)(iVar8 + 0x10bc) = uVar2;
      *(undefined4 *)(iVar8 + 0x1d0) = uVar3;
      *(undefined4 *)(iVar8 + 0x1b8) = uVar3;
      *(undefined4 *)(iVar8 + 0x10c0) = uVar3;
      *(undefined4 *)(iVar8 + 0x1d4) = uVar4;
      *(undefined4 *)(iVar8 + 0x1bc) = uVar4;
      *(undefined4 *)(iVar8 + 0x10c4) = uVar4;
      *(undefined4 *)(iVar8 + 0x68) = DAT_0093b0cc;
      *(undefined4 *)(iVar8 + 0x6c) = DAT_0093b0d0;
      *(undefined4 *)(iVar8 + 0x70) = DAT_0093b0d4;
      FUN_005728a0(iVar8);
      if (bVar5) {
        FUN_00572660(iVar8,0);
      }
    }
  }
  return 1;
}

