/* Ghidra pseudocode, not original source.
 * ev_846633128d4cd55df9225f061f87b742b0c1598eeb1c7e5f9192575f77c77f04
 * Entry: 0x50e7a0; label: FUN_0050e7a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050e7a0(int param_1,float param_2)

{
  char cVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  float10 fVar7;
  int local_81c;
  float local_818;
  int local_814;
  int local_810;
  double local_80c;
  undefined1 local_804 [512];
  undefined1 local_604 [512];
  undefined1 local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_81c;
  dVar2 = (double)param_2;
  iVar3 = 0;
  local_814 = 0;
  local_81c = 1;
  local_80c = dVar2;
  if (dVar2 < 0.0 != (dVar2 == 0.0)) {
    __security_check_cookie(local_4 ^ (uint)&local_81c);
    return;
  }
  do {
    local_810 = 0;
    local_818 = 0.0;
    iVar5 = local_814;
    iVar4 = iVar3;
    if (0.0 < dVar2) {
      do {
        iVar3 = iVar4;
        if (local_810 != 0) break;
        iVar3 = FUN_0050e730(param_1,iVar4);
        iVar5 = iVar3 - local_814;
        if (0x1ff < iVar5) {
          iVar5 = 0x1ff;
        }
        FUN_004ef660(local_804,local_814 + param_1,iVar5);
        local_804[iVar5] = 0;
        FUN_0050c3e0(local_804,local_604);
        iVar5 = DAT_00921ea0;
        if (DAT_00921ea0 == 0) {
          iVar5 = DAT_00921e8c;
        }
        FUN_0050c050(local_604,local_404,iVar5);
        fVar7 = (float10)FUN_005d0c50(DAT_00921e8c,local_404);
        local_818 = (float)fVar7;
        cVar1 = *(char *)(iVar3 + param_1);
        while (cVar1 == ' ') {
          iVar3 = iVar3 + 1;
          cVar1 = *(char *)(iVar3 + param_1);
        }
        if (*(char *)(iVar3 + param_1) == '\0') {
          local_810 = 1;
        }
        if ((*(char *)(iVar3 + param_1) == '\\') && (*(char *)(iVar3 + 1 + param_1) == 'n')) {
          local_810 = 1;
        }
        iVar5 = iVar4;
        iVar4 = iVar3;
        dVar2 = local_80c;
      } while ((double)local_818 < local_80c);
    }
    if (*(char *)(iVar3 + param_1) == '\0') {
      if (param_2 < local_818 != (param_2 == local_818)) {
        local_81c = local_81c + 1;
        *(undefined1 *)(iVar5 + -1 + param_1) = 10;
      }
      __security_check_cookie(local_4 ^ (uint)&local_81c);
      return;
    }
    if ((*(char *)(iVar3 + param_1) == '\\') && (*(char *)(iVar3 + 1 + param_1) == 'n')) {
      *(undefined1 *)(iVar3 + 1 + param_1) = 0x20;
      iVar5 = iVar3 + 1;
    }
    bVar6 = iVar5 == local_814;
    local_814 = iVar5;
    if (bVar6) {
      local_814 = iVar3;
    }
    local_81c = local_81c + 1;
    *(undefined1 *)(local_814 + -1 + param_1) = 10;
  } while( true );
}

