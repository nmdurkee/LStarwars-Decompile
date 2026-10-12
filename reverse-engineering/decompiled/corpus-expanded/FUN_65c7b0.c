/* Ghidra pseudocode, not original source.
 * ev_713fd5a551a5a644e53628cf932656c6d009da906ec29e05de784cd201c28f1f
 * Entry: 0x65c7b0; label: FUN_0065c7b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x0065c7ea) */
/* WARNING: Removing unreachable block (ram,0x0065c81f) */

void FUN_0065c7b0(undefined4 param_1)

{
  int iVar1;
  longlong lVar2;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_24;
  iVar1 = 0;
  _sprintf(local_24,"pictures\\cub%03d_%d.bmp",0,param_1);
  lVar2 = FUN_004fa690(local_24);
  while ((0 < lVar2 && (iVar1 != 999))) {
    iVar1 = iVar1 + 1;
    _sprintf(local_24,"pictures\\cub%03d_%d.bmp",iVar1,param_1);
    lVar2 = FUN_004fa690(local_24);
  }
  _sprintf(local_24,"pictures\\cub%03d_",iVar1);
  FUN_006de9a0(local_24,1,0x3f800000,0x3f800000,param_1,0,0);
  __security_check_cookie(local_4 ^ (uint)local_24);
  return;
}

