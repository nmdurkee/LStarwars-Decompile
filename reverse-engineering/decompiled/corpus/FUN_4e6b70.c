/* Ghidra analysis pseudocode, not original source.
 * ev_1b769233bdb8589f5b6c19d1b053d2efd2e6005a2a8cafb96b11ff416f994ddb
 * Entry: 0x4e6b70; label: FUN_004e6b70
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e6b70(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int local_8;
  short local_4;
  
  local_8 = 0;
  if (0 < DAT_0088a284) {
    piVar4 = &DAT_0088964c;
    do {
      iVar2 = *piVar4;
      if (iVar2 == 0) {
        piVar1 = piVar4 + -3;
        iVar2 = FUN_005cfd60(piVar1);
        if (iVar2 != 0) {
          *(undefined1 *)((int)piVar4 + 10) = 0;
          iVar2 = FUN_005d0330(piVar1);
          if (iVar2 != 0) {
            uVar3 = FUN_006e6b90();
            FUN_005b4dd0(iVar2,uVar3);
            uVar3 = FUN_006e6b90();
            FUN_005b5060(iVar2,uVar3);
            FUN_005ea660(piVar1);
            goto LAB_004e6d10;
          }
        }
LAB_004e6cf0:
        if (*(char *)((int)piVar4 + 10) == '\0') {
          *(undefined1 *)((int)piVar4 + 10) = 1;
          if (*piVar4 != 0) {
            *(undefined4 *)(*piVar4 + 0xa0) = 0;
            FUN_004e66c0(*piVar4);
          }
        }
      }
      else {
        if (((*(uint *)(iVar2 + 0x94) & 0x4000) == 0) || ((*(uint *)(iVar2 + 0x94) & 1) != 0))
        goto LAB_004e6cf0;
        *(undefined1 *)((int)piVar4 + 10) = 0;
        local_4 = (short)(int)ROUND((float)(int)(short)piVar4[1] * _DAT_00925018);
        *(short *)(iVar2 + 0xe8) = *(short *)(iVar2 + 0xe8) + local_4;
        local_4 = (short)(int)ROUND((float)(int)*(short *)((int)piVar4 + 6) * _DAT_00925018);
        *(short *)(*piVar4 + 0xea) = *(short *)(*piVar4 + 0xea) + local_4;
        local_4 = (short)(int)ROUND((float)(int)(short)piVar4[2] * _DAT_00925018);
        *(short *)(*piVar4 + 0xec) = *(short *)(*piVar4 + 0xec) + local_4;
        *(uint *)(*piVar4 + 0x94) = *(uint *)(*piVar4 + 0x94) | 0x10000;
        FUN_005687f0(*piVar4);
      }
LAB_004e6d10:
      local_8 = local_8 + 1;
      piVar4 = piVar4 + 6;
    } while (local_8 < DAT_0088a284);
  }
  return;
}

