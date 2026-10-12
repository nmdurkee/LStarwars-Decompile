/* Ghidra pseudocode, not original source.
 * ev_901c6aaecd0b47868ef1d3f758584dfae83b8347f4e0d529523c41e91b06b177
 * Entry: 0x6d9a00; label: FUN_006d9a00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d9a00(void *param_1,int param_2,undefined4 param_3)

{
  FILE *_File;
  char *pcVar1;
  int local_408;
  undefined1 local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_408;
  FUN_004f1f10(local_404,param_3);
  FUN_004f1e80(local_404,"Mappings.dat");
  _File = (FILE *)FUN_006dd9e0(local_404,&DAT_007516c0,0,&DAT_0076156c);
  if (_File != (FILE *)0x0) {
    local_408 = 0x4d415056;
    _fwrite(&local_408,4,1,_File);
    local_408 = 0x13;
    _fwrite(&local_408,4,1,_File);
    _fwrite(param_1,param_2 * 0x9c,1,_File);
    _fclose(_File);
  }
  local_408 = 0;
  if (0 < param_2) {
    do {
      pcVar1 = (char *)(local_408 * 0x9c + (int)param_1);
      if ((*pcVar1 != '\0') && (DAT_029755a0 != '\0')) {
        FUN_006d6de0(param_3,pcVar1);
      }
      local_408 = local_408 + 1;
    } while (local_408 < param_2);
  }
  __security_check_cookie(local_4 ^ (uint)&local_408);
  return;
}

