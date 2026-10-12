/* Ghidra pseudocode, not original source.
 * ev_581650960e40fbf8034e5bec09e71430d76f0976c291edf1f63134fb2e6d6ade
 * Entry: 0x6d6de0; label: FUN_006d6de0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d6de0(undefined4 param_1,char *param_2)

{
  FILE *_File;
  size_t _Size;
  undefined1 local_c44 [64];
  char local_c04 [1024];
  undefined1 local_804 [2048];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_c44;
  if (*param_2 != '\0') {
    FUN_006d3b30(param_2,local_c44);
    _sprintf(local_c04,"%s%s_v%d.txt",param_1,local_c44,(int)*(short *)(param_2 + 0x5e));
    _File = (FILE *)FUN_006dd9e0(local_c04,&DAT_007516c0,0,&DAT_0076f4d8);
    if (_File != (FILE *)0x0) {
      FUN_006d3b90(local_804,param_2);
      _Size = FUN_004f1ff0(local_804);
      _fwrite(local_804,_Size,1,_File);
      _fclose(_File);
    }
  }
  __security_check_cookie(local_4 ^ (uint)local_c44);
  return;
}

