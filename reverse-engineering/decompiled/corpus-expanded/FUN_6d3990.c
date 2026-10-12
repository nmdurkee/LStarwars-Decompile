/* Ghidra pseudocode, not original source.
 * ev_c1426acf87a342a1866e519dab13ac5b40d9f4eac6e37fcdd4b99f9d53dd1e8b
 * Entry: 0x6d3990; label: FUN_006d3990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d3990(void *param_1,undefined4 param_2)

{
  FILE *_File;
  long lVar1;
  int local_40c;
  int local_408;
  undefined1 local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_40c;
  local_40c = 0;
  FUN_004f1f10(local_404,param_2);
  FUN_004f1e80(local_404,"Mappings.dat");
  _memset(param_1,0,0x2700);
  _File = (FILE *)FUN_006dd9e0(local_404,&DAT_007516c0,0,&DAT_00761558);
  if (_File != (FILE *)0x0) {
    _fseek(_File,0,2);
    lVar1 = _ftell(_File);
    _fseek(_File,0,0);
    FUN_006e89b3(&local_408,4,1,_File);
    if (local_408 == 0x4d415056) {
      FUN_006e89b3(&local_40c,4,1,_File);
      lVar1 = lVar1 + -8;
    }
    else {
      _fseek(_File,0,0);
    }
    if (local_40c == 0x13) {
      FUN_006e89b3(param_1,lVar1,1,_File);
    }
    _fclose(_File);
  }
  __security_check_cookie(local_4 ^ (uint)&local_40c);
  return;
}

