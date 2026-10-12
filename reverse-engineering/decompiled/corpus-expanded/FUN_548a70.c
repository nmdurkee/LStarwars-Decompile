/* Ghidra pseudocode, not original source.
 * ev_f0f87d832dbe8e7fa4eaa2c5681d260c3f1d1a42269eaf7f506f4d6846a5d20b
 * Entry: 0x548a70; label: FUN_00548a70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_00548a70(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  
  piVar1 = param_2;
  FUN_00694c20("audio\\music.cfg",0,param_2,*param_3);
  FUN_00695170(&param_2,0);
  PTR_DAT_00810360 = &DAT_0075eb28;
  puVar2 = (undefined4 *)(*piVar1 + 3U & 0xfffffffc);
  *puVar2 = 0;
  DAT_009248c0 = puVar2 + 7;
  *(undefined2 *)DAT_009248c0 = 0xffff;
  DAT_00924dc4 = puVar2 + 0xe;
  *(undefined2 *)DAT_00924dc4 = 0xffff;
  *piVar1 = (int)(puVar2 + 0xf);
  return param_2;
}

