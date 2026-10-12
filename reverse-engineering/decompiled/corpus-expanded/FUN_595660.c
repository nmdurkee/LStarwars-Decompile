/* Ghidra pseudocode, not original source.
 * ev_5297a07726b91b44a37fb2d5f8434cfe859173f36b4cfd633cbfa32546391649
 * Entry: 0x595660; label: FUN_00595660
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00595660(undefined4 param_1,undefined4 param_2)

{
  float10 fVar1;
  undefined *puVar2;
  float fVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar2 = &DAT_009559d8;
  fVar1 = (float10)FUN_006367d0(&DAT_009559d8);
  fVar3 = (float)fVar1;
  FUN_00636010(&DAT_009559d8,1,puVar2,fVar3);
  FUN_006371d0(param_1,&DAT_009559d8,&DAT_00973718,0,0x10,0x3f800000);
  fVar1 = (float10)FUN_006367d0(&DAT_009559d8);
  if (fVar1 == (float10)0.0) {
    FUN_006367f0(&DAT_009559d8,fVar3);
  }
  FUN_00595540(&DAT_009559d8,param_2);
  FUN_00636420(&DAT_009559d8);
  local_10 = _DAT_00955a98;
  local_c = _DAT_00955a9c;
  local_8 = _DAT_00955aa0;
  local_4 = 0x43000000;
  FUN_00607530(&local_10);
  return;
}

