/* Ghidra pseudocode, not original source.
 * ev_d287e844ea66f87c3c60c812c2454ec5cd238ea97f1ed9ffb4b19045dfabbd11
 * Entry: 0x4802e0; label: FUN_004802e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004802e0(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  float fVar3;
  char cVar4;
  
  iVar1 = *param_3;
  iVar2 = *(int *)(*(int *)(iVar1 + 0x108c) + 4);
  if ((*(char *)(iVar1 + 0x7b5) == DAT_00802874) && (*(int *)(iVar1 + 0x798) == iVar2)) {
    FUN_0055dd70(iVar1,iVar2,1,0x32,0);
    *(undefined4 *)(iVar1 + 0x3d8) = 0;
    *(undefined4 *)(iVar1 + 0x3cc) = *(undefined4 *)(iVar1 + 0x5c);
    *(undefined4 *)(iVar1 + 0x3d0) = *(undefined4 *)(iVar1 + 0x60);
    *(undefined4 *)(iVar1 + 0x3d4) = *(undefined4 *)(iVar1 + 100);
    if (*(int *)(iVar1 + 0x498) == *(int *)(iVar1 + 0x424)) {
      fVar3 = *(float *)(iVar1 + 0x480) - *(float *)(iVar1 + 0x60);
      if (_DAT_007fa294 < fVar3) {
        *(undefined1 *)(iVar1 + 0x1072) = 1;
        *(undefined1 *)(iVar1 + 0x1087) = 0x32;
        return 1;
      }
      if (fVar3 < -_DAT_007fa294) {
        *(undefined1 *)(iVar1 + 0x1072) = 2;
      }
      *(undefined1 *)(iVar1 + 0x1087) = 0x32;
      return 1;
    }
    if (*(char *)(iVar1 + 0x1087) == '\0') {
      fVar3 = (*(float *)(*(int *)(iVar1 + 0x108c) + 0xc) + *(float *)(*(int *)(iVar1 + 0x44c) + 8))
              - *(float *)(iVar1 + 0x60);
      if (fVar3 <= _DAT_007fa294) {
        if ((-_DAT_007fa294 <= fVar3) ||
           (*(undefined1 *)(iVar1 + 0x1072) = 2, (*(byte *)(iVar1 + 0xe24) & 0x80) != 0))
        goto LAB_00480443;
      }
      else {
        *(undefined1 *)(iVar1 + 0x1072) = 1;
        if (*(float *)(iVar1 + 0x778) <= 0.0) {
LAB_00480443:
          *(undefined4 *)(iVar1 + 0x3d8) = 0;
          *(undefined4 *)(iVar1 + 0x3cc) = *(undefined4 *)(iVar1 + 0x5c);
          *(undefined4 *)(iVar1 + 0x3d0) = *(undefined4 *)(iVar1 + 0x60);
          *(undefined4 *)(iVar1 + 0x3d4) = *(undefined4 *)(iVar1 + 100);
          FUN_0043cbb0(iVar1,*(int *)(iVar1 + 0x44c),*(undefined4 *)(iVar1 + 0x1094),8);
          return 1;
        }
      }
      return 1;
    }
    cVar4 = *(char *)(iVar1 + 0x1087) + -1;
    *(char *)(iVar1 + 0x1087) = cVar4;
    if ((cVar4 != '\0') && ((*(byte *)(iVar1 + 0x4a2) & 1) == 0)) {
      return 1;
    }
  }
  FUN_0043cbf0(iVar1);
  return 0;
}

