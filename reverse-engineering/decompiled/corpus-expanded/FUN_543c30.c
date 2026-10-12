/* Ghidra pseudocode, not original source.
 * ev_c5dfc397922749c3a3d752de14fd9803558ba6adea5c02b0f86cafc5797b3dfb
 * Entry: 0x543c30; label: FUN_00543c30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_00543c30(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char *_Filename;
  FILE *_File;
  undefined1 local_202c [20];
  int local_2018;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_202c;
  _Filename = (char *)FUN_005436e0(param_1);
  _File = _fopen(_Filename,"rb");
  if (_File != (FILE *)0x0) {
    FUN_006e89b3(local_202c,0x2028,1,_File);
    if (local_2018 != 0) {
      _fseek(_File,local_2018,1);
    }
    FUN_006e89b3(param_2,param_3,1,_File);
    _fclose(_File);
    __security_check_cookie(local_4 ^ (uint)local_202c);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)local_202c);
  return;
}

