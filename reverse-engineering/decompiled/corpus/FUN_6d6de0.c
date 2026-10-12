/* Ghidra analysis pseudocode, not original source.
 * ev_1cd547681849579fe9db2ab86a66300dc334807e6004e2ad8358d218d877a353
 * Entry: 0x6d6de0; label: FUN_006d6de0
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

