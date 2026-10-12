/* Ghidra analysis pseudocode, not original source.
 * ev_967bc49bfb89c9289ebafb6996ca9c72d569b4a48639dbecd20a21d28d62ec51
 * Entry: 0x452a60; label: FUN_00452a60
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00452a60(undefined4 param_1,int param_2,int param_3)

{
  uint *puVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  float10 fVar11;
  float in_stack_0000001c;
  int *piVar12;
  int *local_2c;
  int *local_28;
  int local_24 [3];
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  if (*(int *)(PTR_DAT_00802c54 + 0x4678) == 0) {
    return 0;
  }
  if (param_3 == 0) {
    return 0;
  }
  piVar12 = *(int **)(param_3 + 0xd0);
  if (piVar12 == (int *)0x0) {
    return 0;
  }
  if (*piVar12 == 0) {
    return 0;
  }
  iVar3 = *(int *)(PTR_DAT_00802c54 + 0x4678);
  if (*(char *)(*(byte *)((int)piVar12 + 0x28d) + 0x42c0 + iVar3) == -1) {
    return 0;
  }
  iVar10 = (int)*(char *)(*(byte *)((int)piVar12 + 0x28d) + 0x42c0 + iVar3);
  iVar4 = *piVar12;
  piVar9 = (int *)(*(char *)(*(byte *)((int)piVar12 + 0x28d) + 0x4280 + iVar3) * 0x214 + iVar3);
  piVar5 = (int *)piVar9[iVar10 + 1];
  local_2c = (int *)0x0;
  if (*(byte *)((int)piVar5 + 6) == DAT_008025d4) {
    iVar3 = *piVar5;
    local_2c = piVar12 + 0x20;
    fVar11 = (float10)FUN_00556cd0(iVar3,local_2c,local_24,local_18,1);
    if (fVar11 == (float10)-1.0) {
      fVar11 = (float10)FUN_00556cd0(iVar3,local_2c,local_24,local_18,0);
      if (fVar11 == (float10)-1.0) goto LAB_00452d2a;
      FUN_005b3860(local_24,local_24,local_18,0x3f000000);
      piVar12 = local_24;
    }
    else {
      FUN_005b3860(local_24,local_24,local_18,0x3f000000);
      piVar12 = local_24;
    }
  }
  else {
    if (*(byte *)((int)piVar5 + 6) == DAT_00802460) {
      iVar3 = *piVar5;
      if ((*(char *)(iVar4 + 0x7b5) == DAT_00802874) && (*(int *)(iVar4 + 0x798) == iVar3)) {
        *(undefined1 *)(iVar4 + 0x1088) = 5;
        FUN_0055dd70(iVar4,iVar3,1,0x32,0);
        FUN_0043cbf0(iVar4);
        local_2c = (int *)0x0;
        local_28 = &DAT_0093d7f0;
        do {
          if (local_2c != (int *)0x0) goto LAB_00452c9d;
          iVar3 = *local_28;
          piVar12 = local_2c;
          if ((iVar3 != 0) && (*(char *)(iVar3 + 0x7b5) == 'F')) {
            iVar10 = 0;
            piVar5 = piVar9;
            if (*(byte *)(piVar9 + 0x83) != 0) {
              do {
                piVar6 = (int *)piVar5[1];
                if ((piVar6 != (int *)0x0) &&
                   (piVar12 = (int *)iVar3, *piVar6 == *(int *)(iVar3 + 0x798))) break;
                iVar10 = iVar10 + 1;
                piVar5 = piVar5 + 1;
                piVar12 = local_2c;
              } while (iVar10 < (int)(uint)*(byte *)(piVar9 + 0x83));
            }
          }
          local_2c = piVar12;
          local_28 = local_28 + 1;
        } while ((int)local_28 < 0x93d7f8);
        if (local_2c == (int *)0x0) {
          return 0;
        }
LAB_00452c9d:
        if (*(float *)(iVar4 + 0x60) + 0.05 < *(float *)(DAT_0093d810 + 0x60)) {
          *(undefined1 *)(iVar4 + 0x1072) = 1;
          return 0;
        }
        if (*(float *)(iVar4 + 0x60) - 0.05 <= *(float *)(DAT_0093d810 + 0x60)) {
          return 0;
        }
        *(undefined1 *)(iVar4 + 0x1072) = 2;
        return 0;
      }
      FUN_0055dd70(iVar4,iVar3,1,0x32,0);
    }
    piVar12 = piVar9 + iVar10 * 0xf + 0xd;
  }
  FUN_0052fcb0(param_3,piVar12,0,piVar9 + iVar10 * 0xf + 0x11,1,0);
LAB_00452d2a:
  piVar12 = (int *)piVar9[iVar10 + 1];
  if (piVar12 != (int *)0x0) {
    uVar7 = (uint)*(byte *)((int)piVar12 + 6);
    if (uVar7 == DAT_007faaa4) {
      if (*(int *)(*(int *)(*(int *)(iVar4 + 0x50) + 0xc) + 0x174) == 0) {
        if ((DAT_0093b2a4 != 0) &&
           (in_stack_0000001c = *(float *)(param_2 + 0x9c) - in_stack_0000001c,
           *(float *)(param_2 + 0x9c) = in_stack_0000001c, in_stack_0000001c < 0.0)) {
          *(undefined4 *)(param_2 + 0x9c) = 0x3f000000;
          puVar1 = (uint *)(*(int *)(iVar4 + 0xca4) + 8);
          *puVar1 = *puVar1 | DAT_0080228c;
          return 0;
        }
      }
      else {
        iVar3 = *piVar12;
        fVar11 = (float10)FUN_005b3cf0(param_3 + 0x14c,piVar9 + iVar10 * 0xf + 0xd,local_c);
        if ((float)fVar11 < _DAT_00801c6c * _DAT_00801c6c) {
          *(int *)(param_3 + 0x1e4) = iVar3 + 0x68;
          puVar1 = (uint *)(*(int *)(iVar4 + 0xca4) + 8);
          *puVar1 = *puVar1 | DAT_00802280;
          return 0;
        }
      }
    }
    else if (uVar7 == DAT_008025d4) {
      if ((*(char *)(iVar4 + 0x281) != '\0') &&
         (fVar11 = (float10)FUN_005b3cf0(local_2c,local_24,0),
         fVar11 < (float10)*(float *)(param_3 + 0x120))) {
        FUN_005b3860(local_24,local_24,local_18,0xbf000000);
        FUN_0052fcb0(param_3,local_24,0,piVar9 + iVar10 * 0xf + 0x11,1,0);
        *(uint *)(iVar4 + 0xef4) = *(uint *)(iVar4 + 0xef4) | 0x20000;
        *(undefined4 *)(iVar4 + 0x1d8) = 0;
        return 0;
      }
    }
    else if (uVar7 == DAT_007f8cc4) {
      iVar3 = *piVar12;
      if ((*(byte *)(iVar3 + 0x74) & 0x10) == 0) {
        iVar8 = FUN_0055bc80(iVar4,0);
      }
      else {
        iVar8 = FUN_0055bc80(iVar4,1);
      }
      if (iVar8 == 0) {
        if ((DAT_0093b2a4 != 0) &&
           (in_stack_0000001c = *(float *)(param_2 + 0x9c) - in_stack_0000001c,
           *(float *)(param_2 + 0x9c) = in_stack_0000001c, in_stack_0000001c < 0.0)) {
          *(undefined4 *)(param_2 + 0x9c) = 0x3f000000;
          puVar1 = (uint *)(*(int *)(iVar4 + 0xca4) + 8);
          *puVar1 = *puVar1 | DAT_0080228c;
          return 0;
        }
      }
      else {
        fVar11 = (float10)FUN_005b3cf0(param_3 + 0x14c,piVar9 + iVar10 * 0xf + 0xd,local_c);
        if ((float)fVar11 < _DAT_00801c6c * _DAT_00801c6c) {
          *(int *)(param_3 + 0x1e4) = iVar3 + 0x1c;
          puVar2 = (ushort *)(*(int *)(iVar4 + 0xca4) + 0x5a);
          *puVar2 = *puVar2 | 4;
          *(int *)(iVar4 + 0x10cc) = iVar3;
          return 0;
        }
      }
    }
    else if (uVar7 == DAT_00802460) {
      iVar3 = *piVar12;
      if (*(char *)(param_2 + 0x68) != '\0') {
        if (*(char *)(iVar4 + 0x7b5) == '\0') {
          FUN_0055dd70(iVar4,iVar3,1,0x32,0);
          FUN_0052fcb0(param_3,iVar3 + 0x24,0,piVar9 + iVar10 * 0xf + 0x11,7,
                       *(undefined4 *)(param_3 + 0x180));
        }
        else {
          *(undefined1 *)(param_2 + 0x68) = 1;
        }
        if (*(char *)(param_2 + 0x68) != '\0') {
          return 0;
        }
      }
      fVar11 = (float10)FUN_005b3cf0(param_3 + 0x14c,piVar9 + iVar10 * 0xf + 0xd,local_c);
      if ((float)fVar11 < _DAT_00801c6c * _DAT_00801c6c) {
        *(undefined1 *)(param_2 + 0x68) = 1;
        FUN_0055dd70(iVar4,iVar3,1,0x32,0);
        puVar1 = (uint *)(*(int *)(iVar4 + 0xca4) + 8);
        *puVar1 = *puVar1 | DAT_00802278;
      }
    }
  }
  return 0;
}

