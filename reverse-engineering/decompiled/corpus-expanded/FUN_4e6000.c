/* Ghidra pseudocode, not original source.
 * ev_9a3410a9c272a2064cc0564fa84db44ccced53000acc775659afcf5219797551
 * Entry: 0x4e6000; label: FUN_004e6000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e6000(int param_1,undefined4 param_2)

{
  int iVar1;
  int *_Dst;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  int local_34;
  undefined *local_30;
  undefined1 *local_2c;
  int local_28;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_34;
  if ((DAT_0088a530 == '\0') || ((DAT_00951b50 != 0 && (DAT_0088a418 == 0)))) {
    local_34 = 1;
    local_2c = &DAT_0088a43c;
    piVar3 = &DAT_0088a414;
    piVar2 = &DAT_0088a418;
    _Dst = &DAT_0088a410;
    local_30 = &DAT_0088a41c;
    local_28 = 4;
    do {
      _memset(_Dst,0,0x30);
      _sprintf(local_24,"trooper_cannon%d",local_34);
      iVar1 = FUN_0058e980(param_1,local_24);
      *piVar3 = iVar1;
      if (iVar1 != 0) {
        _sprintf(local_24,"troopercannon_%d",local_34);
        iVar1 = FUN_00440120(*(undefined4 *)(param_1 + 0x2ae8),local_24);
        *piVar2 = iVar1;
        if (iVar1 != 0) {
          FUN_004f1f10(local_30,local_24);
        }
      }
      _sprintf(local_24,"BASE%d",local_34);
      iVar1 = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802644,local_24);
      bVar4 = DAT_00951b50 == 0;
      *_Dst = iVar1;
      if (bVar4) {
        if ((*piVar3 != 0) && (*piVar2 != 0)) {
          if ((*(uint *)(*(int *)(param_1 + 0x130) + 0x281c) & 1 << ((char)local_34 - 1U & 0x1f)) ==
              0) {
            if (*_Dst != 0) {
              FUN_0055a2b0(*(undefined4 *)(param_1 + 0x2ac8),*_Dst,1,1);
              FUN_005579d0(*(undefined4 *)*_Dst);
            }
            FUN_00590ba0(*piVar3);
            FUN_005900a0(*piVar3,0);
            *local_2c = 0;
            FUN_0041f6d0(local_24,0,0);
            FUN_0062c560(*(undefined4 *)(param_1 + 0x134),0x5c,*piVar2 + 0x80);
            iVar1 = *piVar2;
            iVar1 = FUN_0043d890(param_2,iVar1 + 0x80,*(undefined2 *)(iVar1 + 0x27a),"CannonTrooper"
                                 ,iVar1 + 0x420,0,0,0,0,0,0);
            if (iVar1 != 0) {
              FUN_00488730(iVar1,*piVar2,0,1);
            }
          }
          else {
            FUN_00590c10(*piVar3,0,0);
            *local_2c = 1;
          }
        }
LAB_004e621a:
        local_30 = local_30 + 0x30;
        _Dst = _Dst + 0xc;
        piVar2 = piVar2 + 0xc;
        piVar3 = piVar3 + 0xc;
      }
      else if (*piVar2 != 0) goto LAB_004e621a;
      local_2c = local_2c + 0x30;
      local_34 = local_34 + 1;
      local_28 = local_28 + -1;
    } while (local_28 != 0);
    DAT_0088a530 = '\x01';
    local_28 = 0;
  }
  __security_check_cookie(local_4 ^ (uint)&local_34);
  return;
}

