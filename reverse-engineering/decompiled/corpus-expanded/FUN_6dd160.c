/* Ghidra pseudocode, not original source.
 * ev_3968740630932d2cb6945455b13b10dc603e92ef7b36def715db8f60cd47147a
 * Entry: 0x6dd160; label: FUN_006dd160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006dd160(char param_1)

{
  HRESULT HVar1;
  BSTR bstrString;
  int iVar2;
  undefined1 auStack_218 [3];
  char local_215;
  int *local_214;
  int local_210;
  WCHAR local_20c;
  undefined1 local_20a [518];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)auStack_218;
  local_210 = 1;
  local_214 = (int *)0x0;
  HVar1 = CoInitialize((LPVOID)0x0);
  local_215 = -1 < HVar1;
  HVar1 = CoCreateInstance((IID *)&DAT_00775fb0,(LPUNKNOWN)0x0,1,(IID *)&DAT_00775fc0,&local_214);
  if ((HVar1 < 0) || (local_214 == (int *)0x0)) {
    local_210 = 1;
  }
  else {
    local_20c = L'\0';
    _memset(local_20a,0,0x206);
    MultiByteToWideChar(0,0,&DAT_02989580,0x104,&local_20c,0x104);
    bstrString = SysAllocString(&local_20c);
    iVar2 = (**(code **)(*local_214 + 0x18))(local_214,bstrString,&local_210);
    if (bstrString != (BSTR)0x0) {
      SysFreeString(bstrString);
    }
    if (iVar2 < 0) {
      local_210 = 0;
    }
  }
  if (local_214 != (int *)0x0) {
    (**(code **)(*local_214 + 8))(local_214);
  }
  if (local_215 != '\0') {
    CoUninitialize();
  }
  if ((local_210 == 0) && (param_1 != '\0')) {
    FUN_004f5240();
    MessageBoxA(DAT_00924864,"You do not have sufficient permissions to play this game.",
                "Insufficient Permissions",0x10);
  }
  __security_check_cookie(local_4 ^ (uint)auStack_218);
  return;
}

