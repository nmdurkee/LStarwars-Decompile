/* Ghidra pseudocode, not original source.
 * ev_e9e973cc1e732372fb6e3c1361e2c8e184c78a797f94e34f658706f6700bd0dd
 * Entry: 0x5fde60; label: FUN_005fde60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fde60(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  int local_c;
  float local_8;
  undefined4 local_4;
  
  piVar1 = DAT_0280d384;
  if ((DAT_0280d384 != (int *)0x0) && (DAT_0280d384 != DAT_00986eb4)) {
    DAT_00986eb4 = DAT_0280d384;
    iVar2 = *DAT_0280d384;
    if ((iVar2 == 2) && (DAT_008264c7 == '\0')) {
      *DAT_0280d384 = 1;
    }
    else if (iVar2 != 1) {
      if (iVar2 != 2) {
        return;
      }
      iVar2 = 0;
      piVar4 = DAT_0280d384 + 2;
      do {
        iVar3 = *piVar4;
        if (iVar3 == -1) {
          iVar3 = 1;
        }
        iVar3 = FUN_005e5310(iVar3);
        FUN_006e5630(iVar2,*(undefined4 *)(iVar3 + 0x24));
        FUN_006e54e0(iVar2,1,1);
        FUN_006e54e0(iVar2,2,1);
        FUN_006e54e0(iVar2,5,2);
        FUN_006e54e0(iVar2,6,2);
        FUN_006e54e0(iVar2,7,0);
        iVar2 = iVar2 + 1;
        piVar4 = piVar4 + 1;
      } while (iVar2 < 3);
      local_c = piVar1[5];
      local_8 = -(float)piVar1[6];
      local_4 = 0;
      FUN_007412e0(0x60,&local_c);
      return;
    }
    bVar5 = DAT_02974d1c == 1;
    iVar2 = piVar1[1];
    if (iVar2 == -1) {
      iVar2 = 1;
    }
    iVar2 = FUN_005e5310(iVar2);
    FUN_006e5630(bVar5,*(undefined4 *)(iVar2 + 0x24));
    FUN_006e54e0(bVar5,1,1);
    FUN_006e54e0(bVar5,2,1);
    FUN_006e54e0(bVar5,5,2);
    FUN_006e54e0(bVar5,6,2);
    FUN_006e54e0(bVar5,7,0);
    local_c = piVar1[5];
    local_8 = -(float)piVar1[6];
    local_4 = 0;
    FUN_007412e0(0x60,&local_c);
    return;
  }
  return;
}

