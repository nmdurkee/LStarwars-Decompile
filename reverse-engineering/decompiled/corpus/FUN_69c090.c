/* Ghidra analysis pseudocode, not original source.
 * ev_b9f25343996aedf2297d7d3ade291ed602d662c61207b78e5aec6bfbfbdc583f
 * Entry: 0x69c090; label: FUN_0069c090
 */

int FUN_0069c090(undefined1 *param_1,int param_2,int param_3)

{
  int in_EAX;
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  int extraout_EDX;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  undefined1 *puVar9;
  bool bVar10;
  uint local_3c;
  undefined1 local_38 [4];
  int local_34;
  undefined1 local_28 [36];
  
  while( true ) {
    if (*(int *)(in_EAX + 0x58) == 4) {
      while( true ) {
        puVar9 = param_1;
        if (param_1 == (undefined1 *)0x0) {
          puVar9 = local_28;
        }
        iVar1 = FUN_0069fcc0(in_EAX + 0x78,puVar9);
        param_1 = (undefined1 *)0x0;
        if (iVar1 == -1) {
          return -3;
        }
        if (iVar1 < 1) break;
        local_3c = *(uint *)(puVar9 + 0x14);
        uVar7 = *(uint *)(puVar9 + 0x10);
        iVar1 = FUN_006a11d0(in_EAX + 0x250,puVar9);
        if (iVar1 == 0) {
          iVar1 = FUN_006a2db0(in_EAX + 0x1e0,0);
          if (iVar1 == 0) {
            FUN_006a23b0(in_EAX + 0x1e0,in_EAX + 0x250);
            iVar1 = FUN_006a2db0(in_EAX + 0x1e0,0);
            *(double *)(in_EAX + 0x70) = (double)iVar1 + *(double *)(in_EAX + 0x70);
            *(double *)(in_EAX + 0x68) =
                 (double)(*(int *)(puVar9 + 4) * 8) + *(double *)(in_EAX + 0x68);
            if (((uVar7 & local_3c) != 0xffffffff) && (*(int *)(puVar9 + 0xc) == 0)) {
              if (*(int *)(in_EAX + 4) == 0) {
                iVar1 = 0;
              }
              else {
                iVar1 = *(int *)(in_EAX + 0x60);
                if (0 < iVar1) {
                  uVar2 = *(uint *)(iVar1 * 0x10 + *(int *)(in_EAX + 0x44));
                  bVar10 = uVar7 < uVar2;
                  uVar7 = uVar7 - uVar2;
                  local_3c = (local_3c - *(int *)(iVar1 * 0x10 + 4 + *(int *)(in_EAX + 0x44))) -
                             (uint)bVar10;
                }
              }
              if (((int)local_3c < 1) && ((int)local_3c < 0)) {
                uVar7 = 0;
                local_3c = 0;
              }
              uVar2 = FUN_006a2db0(in_EAX + 0x1e0,0);
              uVar8 = uVar7 - uVar2;
              iVar5 = (local_3c - ((int)uVar2 >> 0x1f)) - (uint)(uVar7 < uVar2);
              if (0 < iVar1) {
                puVar3 = (uint *)(*(int *)(in_EAX + 0x44) + 8);
                do {
                  bVar10 = CARRY4(uVar8,*puVar3);
                  uVar8 = uVar8 + *puVar3;
                  iVar5 = iVar5 + puVar3[1] + (uint)bVar10;
                  puVar3 = puVar3 + 4;
                  iVar1 = iVar1 + -1;
                } while (iVar1 != 0);
              }
              *(uint *)(in_EAX + 0x50) = uVar8;
              *(int *)(in_EAX + 0x54) = iVar5;
            }
            return 1;
          }
          return -0x81;
        }
      }
    }
    if (*(int *)(in_EAX + 0x58) < 2) break;
    do {
      if (param_2 == 0) {
        return 0;
      }
      FUN_0069b340(local_38,0xffffffff,0xffffffff);
      if (extraout_EDX < 0) {
        return -2;
      }
      *(double *)(in_EAX + 0x68) = (double)(local_34 * 8) + *(double *)(in_EAX + 0x68);
      if (*(int *)(in_EAX + 0x58) != 4) goto LAB_0069c1cd;
      iVar1 = FUN_0069ed70(local_38);
      if (*(int *)(in_EAX + 0x5c) == iVar1) goto LAB_0069c1c4;
      iVar1 = FUN_0069ecc0(local_38);
    } while (iVar1 == 0);
    if (param_3 == 0) {
      return -2;
    }
    FUN_006a1ae0(in_EAX + 0x1e0);
    FUN_006a1630(in_EAX + 0x250);
    *(undefined4 *)(in_EAX + 0x58) = 2;
    if (*(int *)(in_EAX + 4) == 0) {
      FUN_006a0180(*(undefined4 *)(in_EAX + 0x48));
      FUN_006a00b0(*(undefined4 *)(in_EAX + 0x4c));
      break;
    }
LAB_0069c1d9:
    iVar5 = FUN_0069ed70(local_38);
    iVar1 = *(int *)(in_EAX + 0x34);
    iVar4 = 0;
    if (0 < iVar1) {
      piVar6 = *(int **)(in_EAX + 0x40);
      do {
        if (*piVar6 == iVar5) break;
        iVar4 = iVar4 + 1;
        piVar6 = piVar6 + 1;
      } while (iVar4 < iVar1);
    }
    if (iVar4 != iVar1) {
      *(int *)(in_EAX + 0x5c) = iVar5;
      *(int *)(in_EAX + 0x60) = iVar4;
      FUN_0069fb50(in_EAX + 0x78,iVar5);
      *(undefined4 *)(in_EAX + 0x58) = 3;
LAB_0069c249:
      iVar1 = FUN_0069bff0();
      if (iVar1 < 0) {
        return iVar1;
      }
LAB_0069c256:
      FUN_0069f7f0(in_EAX + 0x78,local_38);
    }
  }
LAB_0069c1c4:
  if (*(int *)(in_EAX + 0x58) != 4) {
LAB_0069c1cd:
    if (*(int *)(in_EAX + 0x58) < 3) {
      if (*(int *)(in_EAX + 4) != 0) goto LAB_0069c1d9;
      iVar1 = FUN_0069b9c0(*(undefined4 *)(in_EAX + 0x48),*(undefined4 *)(in_EAX + 0x4c),
                           in_EAX + 0x5c);
      if (iVar1 != 0) {
        return iVar1;
      }
      *(int *)(in_EAX + 0x60) = *(int *)(in_EAX + 0x60) + 1;
    }
    goto LAB_0069c249;
  }
  goto LAB_0069c256;
}

