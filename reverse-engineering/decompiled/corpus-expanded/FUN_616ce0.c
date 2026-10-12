/* Ghidra pseudocode, not original source.
 * ev_35392dc412ffe2b2a558f5a6ba3fa7479ff279a31c4c87c94d67c76968103d24
 * Entry: 0x616ce0; label: FUN_00616ce0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00616ce0(void)

{
  ushort *puVar1;
  ushort uVar2;
  undefined4 *puVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *piVar10;
  int iStack_2c;
  int local_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  puVar9 = (undefined4 *)(in_ECX + 0x40);
  local_24 = 0x800;
  do {
    puVar1 = (ushort *)(puVar9 + -4);
    if (*(short *)((int)puVar9 + -0xe) != 0) {
      if (*(char *)(puVar9[-2] + 0xc) == '\0') {
        if ((*puVar1 & 2) == 0) {
          iVar5 = FUN_006be780(*puVar9);
          piVar10 = *(int **)(in_ECX + 0xd1b4 + iVar5 * 0xc);
          iStack_2c = 0;
          for (; piVar10 != (int *)0x0; piVar10 = (int *)piVar10[1]) {
            uVar2 = *(ushort *)(piVar10 + 5);
            if ((*(byte *)((int)piVar10 + 0xe) & 4) != 0) {
              iStack_10 = puVar9[1] + iStack_2c;
              iStack_c = iStack_10 + (uint)uVar2;
              iStack_8 = iStack_10;
              (**(code **)*piVar10)(*puVar9,puVar9[-1],&iStack_10,0,0);
              (**(code **)(*piVar10 + 8))(*puVar9,puVar9[-1],&local_24,0);
            }
            iStack_2c = iStack_2c + (uint)uVar2;
          }
        }
      }
      else {
        *puVar1 = *puVar1 & 0xfffb;
        iVar5 = FUN_006be780(*puVar9);
        iVar7 = 1;
        if (*(int *)(in_ECX + 0xd5b4 + iVar5 * 4) != 0) {
          iVar7 = (**(code **)**(undefined4 **)(in_ECX + 0xd5b4 + iVar5 * 4))(*puVar9,puVar9[-1]);
        }
        iVar6 = DAT_028fec2c;
        if (0.0 < _DAT_0290082c) {
          iVar6 = FUN_006e6b90();
        }
        bVar4 = true;
        if (iVar7 != 0) {
          iVar7 = 0;
          for (puVar3 = *(undefined4 **)(in_ECX + 0xd1b4 + iVar5 * 0xc); puVar3 != (undefined4 *)0x0
              ; puVar3 = (undefined4 *)puVar3[1]) {
            if ((*puVar1 & 2) != 0) {
              *(ushort *)((int)puVar3 + 0xe) = *(ushort *)((int)puVar3 + 0xe) | 8;
            }
            iStack_20 = puVar9[1] + iVar7;
            iStack_1c = iStack_20 + (uint)*(ushort *)(puVar3 + 5);
            iVar7 = iVar7 + (uint)*(ushort *)(puVar3 + 5);
            iStack_18 = iStack_20;
            if ((DAT_028fec10 < iVar6) && ((*(byte *)((int)puVar3 + 0xe) & 0x40) == 0)) {
              bVar4 = false;
            }
            else if ((bVar4) &&
                    (iVar5 = (**(code **)*puVar3)(*puVar9,puVar9[-1],&iStack_20,0,0), iVar5 != 0)) {
              FUN_00616230(puVar1,puVar3,&iStack_20,in_ECX + 0xd8d8);
            }
          }
        }
        if ((*puVar1 & 2) != 0) {
          *puVar1 = *puVar1 & 0xfffd;
        }
      }
    }
    puVar9 = puVar9 + 6;
    local_24 = local_24 + -1;
  } while (local_24 != 0);
  piVar10 = (int *)(in_ECX + 0xd838);
  local_24 = 8;
  do {
    if (*piVar10 != 0) {
      if ((0 < piVar10[3]) && (piVar10[3] < 3)) {
        iVar5 = piVar10[4];
        iVar7 = DAT_028fec2c;
        if (0.0 < _DAT_0290082c) {
          iVar7 = FUN_006e6b90();
        }
        if (iVar5 < *(int *)(in_ECX + 0xc030)) {
          piVar8 = (int *)(in_ECX + 0xc034 + iVar5 * 4);
          do {
            if (DAT_028fec10 <= iVar7) break;
            iVar6 = *piVar8;
            iVar5 = iVar5 + 1;
            piVar8 = piVar8 + 1;
            if ((iVar6 != 0) && (*(int *)(iVar6 + 0xc) != 0)) {
              if (piVar10[3] == 1) {
                FUN_006160b0(iVar6,piVar10);
              }
              if (piVar10[3] == 2) {
                FUN_00616b50(iVar6,piVar10,1);
              }
              iVar7 = (**(code **)(*(int *)*piVar10 + 0x14))();
              if (iVar7 < 0x10) break;
              iVar7 = DAT_028fec2c;
              if (0.0 < _DAT_0290082c) {
                iVar7 = FUN_006e6b90();
              }
            }
          } while (iVar5 < *(int *)(in_ECX + 0xc030));
        }
        if (iVar5 < *(int *)(in_ECX + 0xc030)) {
          piVar10[4] = iVar5;
        }
        else if (piVar10[3] < 3) {
          piVar10[3] = piVar10[3] + 1;
          piVar10[4] = 0;
        }
      }
      FUN_00615ff0();
    }
    piVar10 = piVar10 + 5;
    local_24 = local_24 + -1;
    if (local_24 == 0) {
      FUN_00615ff0();
      piVar10 = (int *)(in_ECX + 0xd8ec);
      iVar5 = 0x20;
      do {
        if (*piVar10 != 0) {
          (*(code *)**(undefined4 **)*piVar10)();
        }
        piVar10 = piVar10 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      return;
    }
  } while( true );
}

