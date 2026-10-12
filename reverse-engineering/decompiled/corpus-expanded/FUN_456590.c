/* Ghidra pseudocode, not original source.
 * ev_8506f68535ad223f61af74cca875ccd9b44b8142143265b685ac08963c75a37f
 * Entry: 0x456590; label: FUN_00456590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00456590(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte local_5;
  int local_4;
  
  iVar8 = 0;
  local_4 = 0;
  local_5 = 0;
  if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
     (*piVar1 != 0)) {
    iVar8 = *piVar1;
  }
  if ((param_6 != 0) && (iVar7 = 0, 0 < param_5)) {
    do {
      iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"torpedo");
      if (iVar3 == 0) {
        iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar7 * 4),"CANBESTOLEN");
        if (iVar3 == 0) {
          local_5 = 0x20;
        }
      }
      else {
        FUN_005147c0(param_3,iVar3 + 8);
        local_4 = FUN_006e6b90();
        if (local_4 < 0) {
          local_4 = 0;
        }
        else {
          iVar3 = FUN_004d23e0(0);
          if (iVar3 < local_4) {
            local_4 = FUN_004d23e0(0);
          }
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < param_5);
  }
  if (iVar8 != 0) {
    piVar1 = (int *)(iVar8 + 0xcc4);
    if (*(int *)(iVar8 + 0xcc4) != 0) {
      FUN_004d22f0(piVar1);
    }
    puVar4 = (undefined1 *)FUN_004d22b0();
    *piVar1 = (int)puVar4;
    if ((puVar4 != (undefined1 *)0x0) && (local_4 != 0)) {
      *puVar4 = (char)local_4;
      *(byte *)(*piVar1 + 1) = *(byte *)(*piVar1 + 1) | local_5;
      iVar7 = 0;
      if (3 < local_4) {
        iVar6 = (local_4 - 4U >> 2) + 1;
        iVar3 = 0x48;
        iVar7 = iVar6 * 4;
        do {
          iVar2 = *piVar1;
          *(undefined4 *)(iVar3 + -0xc + iVar2) = *(undefined4 *)(iVar8 + 0x80);
          *(undefined4 *)(iVar3 + -8 + iVar2) = *(undefined4 *)(iVar8 + 0x84);
          *(undefined4 *)(iVar3 + -4 + iVar2) = *(undefined4 *)(iVar8 + 0x88);
          *(undefined4 *)(*piVar1 + 8) = 0x3f4ccccd;
          *(undefined1 *)(*piVar1 + 3) = 0;
          iVar2 = *piVar1;
          *(undefined4 *)(iVar2 + iVar3) = *(undefined4 *)(iVar8 + 0x80);
          *(undefined4 *)(iVar2 + 4 + iVar3) = *(undefined4 *)(iVar8 + 0x84);
          *(undefined4 *)(iVar2 + 8 + iVar3) = *(undefined4 *)(iVar8 + 0x88);
          *(undefined4 *)(*piVar1 + 8) = 0x3f4ccccd;
          *(undefined1 *)(*piVar1 + 3) = 0;
          iVar2 = *piVar1;
          *(undefined4 *)(iVar3 + 0xc + iVar2) = *(undefined4 *)(iVar8 + 0x80);
          *(undefined4 *)(iVar3 + 0x10 + iVar2) = *(undefined4 *)(iVar8 + 0x84);
          *(undefined4 *)(iVar3 + iVar2 + 0x14) = *(undefined4 *)(iVar8 + 0x88);
          *(undefined4 *)(*piVar1 + 8) = 0x3f4ccccd;
          *(undefined1 *)(*piVar1 + 3) = 0;
          puVar5 = (undefined4 *)(iVar3 + 0x18 + *piVar1);
          *puVar5 = *(undefined4 *)(iVar8 + 0x80);
          puVar5[1] = *(undefined4 *)(iVar8 + 0x84);
          puVar5[2] = *(undefined4 *)(iVar8 + 0x88);
          *(undefined4 *)(*piVar1 + 8) = 0x3f4ccccd;
          iVar3 = iVar3 + 0x30;
          iVar6 = iVar6 + -1;
          *(undefined1 *)(*piVar1 + 3) = 0;
        } while (iVar6 != 0);
      }
      if (iVar7 < local_4) {
        iVar3 = (iVar7 * 3 + 0xf) * 4;
        local_4 = local_4 - iVar7;
        do {
          puVar5 = (undefined4 *)(*piVar1 + iVar3);
          *puVar5 = *(undefined4 *)(iVar8 + 0x80);
          puVar5[1] = *(undefined4 *)(iVar8 + 0x84);
          puVar5[2] = *(undefined4 *)(iVar8 + 0x88);
          *(undefined4 *)(*piVar1 + 8) = 0x3f4ccccd;
          iVar3 = iVar3 + 0xc;
          local_4 = local_4 + -1;
          *(undefined1 *)(*piVar1 + 3) = 0;
        } while (local_4 != 0);
      }
    }
  }
  return 1;
}

