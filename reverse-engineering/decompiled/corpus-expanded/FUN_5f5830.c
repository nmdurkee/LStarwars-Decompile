/* Ghidra pseudocode, not original source.
 * ev_73151266ff1c8f163ed19691e079968d47cc326d45708775e4f70bdc31fc3cf9
 * Entry: 0x5f5830; label: FUN_005f5830
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_005f5830(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_2a24;
  int local_2a20;
  undefined1 *local_2a1c [2];
  int local_2a14;
  undefined1 local_2a10 [272];
  int local_2900;
  undefined1 local_2804 [10240];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_2a24;
  iVar4 = 0;
  if (DAT_00973fcc == 0) {
    if ((*(byte *)(param_1 + 0x74) & 4) != 0) {
      FUN_005c12f0();
      __security_check_cookie(local_4 ^ (uint)&local_2a24);
      return;
    }
    FUN_005fd0d0(*(undefined4 *)(param_1 + 0x80));
    iVar2 = FUN_005f3c80(*(undefined4 *)(param_1 + 0x78),local_2804);
    local_2a20 = iVar2;
    if (DAT_009718dc == 0) {
      if ((iVar2 == 0) || ((*(byte *)(iVar2 + 0x28) & 1) == 0)) {
        FUN_005f5380(iVar2);
      }
    }
    else if ((iVar2 == 0) || ((*(byte *)(iVar2 + 0x28) & 1) == 0)) {
      FUN_005f0ac0();
    }
    if (*(int *)(param_1 + 0x10) != 0) {
      *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | 4;
    }
    FUN_00603960(param_1);
    local_2a1c[0] = *(undefined1 **)(param_1 + 0x78);
    if (local_2a1c[0] == (undefined1 *)0x0) {
      local_2900 = param_1;
      local_2a1c[0] = local_2a10;
    }
    if (((DAT_0080bab4 == 0) || (*(int *)(iVar2 + 0x18) == 0)) ||
       (local_2a24 = 1, DAT_0080ba58 == 0)) {
      local_2a24 = 0;
    }
    if ((((*(byte *)(param_1 + 0x76) & 1) == 0) && (DAT_00973fd0 == 0)) &&
       (0 < *(int *)(param_1 + 0x6c))) {
      iVar2 = 0;
      do {
        iVar1 = iVar2 + *(int *)(param_1 + 0x70);
        if (((*(byte *)(iVar2 + 0xb8 + *(int *)(param_1 + 0x70)) & 2) != 0) &&
           (((local_2a14 = iVar1, local_2a24 == 0 ||
             (iVar3 = *(int *)(iVar1 + 0xc0), (*(byte *)(*(int *)(param_1 + 0x48) + iVar3) & 8) != 0
             )) || ((*(byte *)((iVar3 >> 3) + *(int *)(local_2a20 + 0x1c)) >> ((byte)iVar3 & 7) & 1)
                    != 0)))) {
          if (((iVar1 == 0) || (iVar3 = *(int *)(iVar1 + 0xc4), iVar3 == -1)) || (iVar3 == 0)) {
            iVar3 = iVar1 + 0x40;
          }
          FUN_005f0f00(local_2a1c,iVar3,0,0,0);
        }
        iVar4 = iVar4 + 1;
        iVar2 = iVar2 + 0xd0;
      } while (iVar4 < *(int *)(param_1 + 0x6c));
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_2a24);
  return;
}

