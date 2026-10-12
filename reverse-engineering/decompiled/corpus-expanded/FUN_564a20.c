/* Ghidra pseudocode, not original source.
 * ev_e3b3033091aeb82eb30298db917b9f24103ba523fce1c25e6a380c5931a7a891
 * Entry: 0x564a20; label: FUN_00564a20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00564a20(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (DAT_0095070c == 0) {
    DAT_0095070c = FUN_005ef7f0(param_2,*param_3,param_1);
  }
  iVar1 = DAT_0095070c;
  _memset(&DAT_009505ec,0,0x30);
  if (iVar1 != 0) {
    FUN_005cf5b0(iVar1,&DAT_009505ec,"ball1",1);
    FUN_005cf5b0(DAT_0095070c,&DAT_009505f8,"ball2",1);
    FUN_005cf5b0(DAT_0095070c,&DAT_00950604,"ball3",1);
    FUN_005cf5b0(DAT_0095070c,&DAT_00950610,"ball4",1);
  }
  return;
}

