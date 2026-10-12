/* Ghidra pseudocode, not original source.
 * ev_dfc36d2b541ec0d46ba2179b7939a25d003ccbe30d4bab0c10c333595f465d14
 * Entry: 0x656d40; label: FUN_00656d40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00656d40(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

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
    FUN_006561d0(param_1,param_2,param_3,0,param_4,param_5,param_6,param_7,uVar2,0);
  }
  return;
}

