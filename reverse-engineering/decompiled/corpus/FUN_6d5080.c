/* Ghidra analysis pseudocode, not original source.
 * ev_07efd457ec9a37501bdb802bda98d4fdf679445de954c80baf7ce8f2bb24f771
 * Entry: 0x6d5080; label: FUN_006d5080
 */

/* WARNING: Removing unreachable block (ram,0x006d5196) */
/* WARNING: Removing unreachable block (ram,0x006d51c0) */
/* WARNING: Removing unreachable block (ram,0x006d51cc) */
/* WARNING: Removing unreachable block (ram,0x006d51d6) */
/* WARNING: Removing unreachable block (ram,0x006d51f3) */
/* WARNING: Removing unreachable block (ram,0x006d51ff) */
/* WARNING: Removing unreachable block (ram,0x006d520b) */
/* WARNING: Removing unreachable block (ram,0x006d5221) */
/* WARNING: Removing unreachable block (ram,0x006d523f) */
/* WARNING: Removing unreachable block (ram,0x006d5257) */
/* WARNING: Removing unreachable block (ram,0x006d525b) */
/* WARNING: Removing unreachable block (ram,0x006d5271) */
/* WARNING: Removing unreachable block (ram,0x006d5289) */
/* WARNING: Removing unreachable block (ram,0x006d5291) */
/* WARNING: Removing unreachable block (ram,0x006d52eb) */
/* WARNING: Removing unreachable block (ram,0x006d52a3) */
/* WARNING: Removing unreachable block (ram,0x006d52ab) */
/* WARNING: Removing unreachable block (ram,0x006d52b7) */
/* WARNING: Removing unreachable block (ram,0x006d52c4) */
/* WARNING: Removing unreachable block (ram,0x006d5336) */

undefined1 FUN_006d5080(void)

{
  int *piVar1;
  HRESULT HVar2;
  HRESULT HVar3;
  IID *riid;
  int iVar4;
  uint uVar5;
  BSTR bstrString;
  int *local_7c;
  IUnknown *local_78;
  undefined4 local_74;
  IID *local_6c;
  BSTR local_64;
  int local_50;
  undefined1 local_4c [76];
  
  local_7c = (int *)0x0;
  local_50 = 0;
  _memset(local_4c,0,0x4c);
  local_78 = (IUnknown *)0x0;
  bstrString = (BSTR)0x0;
  local_74 = 0;
  HVar2 = CoInitialize((LPVOID)0x0);
  HVar3 = CoCreateInstance((IID *)&DAT_00775978,(LPUNKNOWN)0x0,1,(IID *)&DAT_00775988,&local_7c);
  if (((-1 < HVar3) && (local_7c != (int *)0x0)) &&
     (local_64 = SysAllocString(L"\\\\.\\root\\cimv2"), local_64 != (BSTR)0x0)) {
    riid = (IID *)SysAllocString(L"Win32_PNPEntity");
    local_6c = riid;
    if (((riid != (IID *)0x0) && (bstrString = SysAllocString(L"DeviceID"), bstrString != (BSTR)0x0)
        ) && ((iVar4 = (**(code **)(*local_7c + 0xc))(local_7c,local_64,0,0,0,0,0,0,&local_78),
              -1 < iVar4 && (local_78 != (IUnknown *)0x0)))) {
      CoSetProxyBlanket(local_78,10,0,(OLECHAR *)0x0,3,3,(RPC_AUTH_IDENTITY_HANDLE)0x0,0);
      (*local_78->lpVtbl[6].QueryInterface)(local_78,riid,(void **)0x0);
    }
    SysFreeString(local_64);
    if (bstrString != (BSTR)0x0) {
      SysFreeString(bstrString);
    }
    if (riid != (IID *)0x0) {
      SysFreeString((BSTR)riid);
    }
  }
  uVar5 = 0;
  do {
    piVar1 = *(int **)(local_4c + uVar5 * 4 + -4);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(local_4c + uVar5 * 4 + -4) = 0;
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x14);
  if (local_7c != (int *)0x0) {
    (**(code **)(*local_7c + 8))(local_7c);
    local_7c = (int *)0x0;
  }
  if (local_78 != (IUnknown *)0x0) {
    (*local_78->lpVtbl->Release)(local_78);
    local_78 = (IUnknown *)0x0;
  }
  if (-1 < HVar2) {
    CoUninitialize();
  }
  return 0;
}

