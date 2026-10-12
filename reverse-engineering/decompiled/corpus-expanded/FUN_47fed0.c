/* Ghidra pseudocode, not original source.
 * ev_d287e844ea66f87c3c60c812c2454ec5cd238ea97f1ed9ffb4b19045dfabbd11
 * Entry: 0x47fed0; label: FUN_0047fed0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0047fed0(float param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float local_c [3];
  
  iVar3 = (int)param_1;
  iVar7 = *(int *)(*(int *)((int)param_1 + 0x158) + 0x7c);
  iVar1 = *param_2;
  iVar6 = (uint)*(byte *)(*(byte *)((int)param_1 + 0x160) + 0x10 + *(int *)((int)param_1 + 0x15c)) *
          0x5c + iVar7;
  iVar7 = (uint)*(byte *)((*(byte *)((int)param_1 + 0x160) == 0) + 0x10 +
                         *(int *)((int)param_1 + 0x15c)) * 0x5c + iVar7;
  iVar4 = FUN_0043c9a0(iVar1,iVar7,0);
  if (iVar4 == 0) {
    piVar2 = *(int **)(iVar1 + 0x108c);
    if ((piVar2 != (int *)0x0) &&
       (((*(int *)(iVar1 + 0x424) != *piVar2 ||
         ((((char)piVar2[2] != -1 && (*(char *)(iVar1 + 0x428) != (char)piVar2[2])) ||
          (*(char *)((int)piVar2 + 9) != '\x01')))) ||
        (((*(char *)(iVar1 + 0x7b5) != DAT_00802874 || (*(int *)(iVar1 + 0x798) != piVar2[1])) &&
         (iVar4 = FUN_0054d410(piVar2[1],iVar1,*(undefined4 *)((int)param_1 + 0x15c)), iVar4 != 0)))
        ))) {
      *(undefined4 *)(iVar1 + 0x108c) = 0;
    }
    if (*(int *)(iVar1 + 0x108c) == 0) {
      uVar5 = FUN_005ab1e0(*(undefined4 *)(PTR_DAT_00802c54 + 0x4674),iVar1,0,0,1,FUN_0047fea0);
      *(undefined4 *)(iVar1 + 0x108c) = uVar5;
    }
    if (*(int *)(iVar1 + 0x108c) == 0) {
      *(undefined4 *)(iVar1 + 0x3d8) = 0;
      *(undefined4 *)(iVar1 + 0x3cc) = *(undefined4 *)(iVar1 + 0x5c);
      *(undefined4 *)(iVar1 + 0x3d0) = *(undefined4 *)(iVar1 + 0x60);
      *(undefined4 *)(iVar1 + 0x3d4) = *(undefined4 *)(iVar1 + 100);
    }
    else {
      iVar4 = *(int *)(*(int *)(iVar1 + 0x108c) + 4);
      FUN_0055dd70(iVar1,iVar4,1,0x32,0);
      if ((*(char *)(iVar1 + 0x7b5) == DAT_00802874) && (*(int *)(iVar1 + 0x798) == iVar4)) {
        *(undefined4 *)(iVar1 + 0x3d8) = 0;
        *(undefined4 *)(iVar1 + 0x3cc) = *(undefined4 *)(iVar1 + 0x5c);
        *(undefined4 *)(iVar1 + 0x3d0) = *(undefined4 *)(iVar1 + 0x60);
        *(undefined4 *)(iVar1 + 0x3d4) = *(undefined4 *)(iVar1 + 100);
        FUN_0043cbb0(iVar1,iVar7,iVar6,7);
        if (*(char *)(iVar1 + 0x1088) != '\0') {
          *(undefined1 *)(iVar1 + 0x1087) = 0x32;
          *(undefined1 *)(iVar1 + 0x1088) = 0;
          return 1;
        }
      }
      else {
        local_c[0] = *(float *)(iVar7 + 4) - *(float *)(iVar6 + 4);
        local_c[1] = 0.0;
        local_c[2] = *(float *)(iVar7 + 0xc) - *(float *)(iVar6 + 0xc);
        param_1 = *(float *)(iVar6 + 0x10);
        if (param_1 < 0.0) {
          param_1 = 0.0;
        }
        FUN_005b3830(local_c,local_c,param_1 / *(float *)(*(int *)(iVar3 + 0x15c) + 0x1c));
        FUN_005b37d0(iVar3 + 0x104,iVar6 + 4,local_c);
        *(undefined4 *)(iVar1 + 0x3d8) = 0;
        iVar4 = FUN_0054d410(iVar4,iVar1,*(undefined4 *)(iVar3 + 0x15c));
        if (iVar4 != 0) {
          *(undefined4 *)(iVar1 + 0x3cc) = *(undefined4 *)(iVar1 + 0x5c);
          *(undefined4 *)(iVar1 + 0x3d0) = *(undefined4 *)(iVar1 + 0x60);
          *(undefined4 *)(iVar1 + 0x3d4) = *(undefined4 *)(iVar1 + 100);
          *(int *)(iVar1 + 0x4ac) = iVar4 + 0x80;
          FUN_0058bfb0(iVar1,iVar4,5,0x3f800000,0,0);
          return 1;
        }
        fVar8 = (float10)FUN_005b3cf0(param_2 + 0x17,iVar3 + 0x104,local_c);
        if ((param_3 != 0) && ((float)fVar8 < _DAT_00801c6c * _DAT_00801c6c)) {
          FUN_0043cbb0(iVar1,iVar7,iVar6,6);
          return 1;
        }
      }
    }
  }
  return 1;
}

