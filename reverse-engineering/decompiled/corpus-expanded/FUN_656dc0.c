/* Ghidra pseudocode, not original source.
 * ev_dfc36d2b541ec0d46ba2179b7939a25d003ccbe30d4bab0c10c333595f465d14
 * Entry: 0x656dc0; label: FUN_00656dc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00656dc0(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  char cVar1;
  undefined4 uVar2;
  
  if ((-1 < param_1) && (*(int *)(DAT_0296209c + param_1 * 4) != 0)) {
    cVar1 = *(char *)(*(int *)(DAT_0296209c + param_1 * 4) + 0x2e);
    if (cVar1 == '\x02') {
      uVar2 = 40000;
    }
    else if (cVar1 == '\x03') {
      uVar2 = 30000;
    }
    else if (cVar1 == '\a') {
      uVar2 = 10000;
    }
    else {
      uVar2 = 20000;
    }
    FUN_006561d0(param_1,param_2,param_3,0,param_4 * 0x1e,_DAT_008108e4,param_5,param_6,uVar2,0);
  }
  return;
}

