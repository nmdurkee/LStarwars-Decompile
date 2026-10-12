/* Ghidra analysis pseudocode, not original source.
 * ev_aee1a4f0943f0e53edaf0cbac59fb891b878b74e3aefed4690394b4ea17c7eca
 * Entry: 0x70b1a0; label: __Getmonths_l
 */

/* Library Function - Single Match
    __Getmonths_l
   
   Library: Visual Studio 2005 Release */

char * __Getmonths_l(localeinfo_struct *param_1)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  errno_t eVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_20 [2];
  int local_18;
  char local_14;
  size_t local_10;
  int local_c;
  char *local_8;
  
  iVar5 = 0;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_20,param_1);
  iVar1 = *(int *)(local_20[0] + 0xd4);
  puVar6 = (undefined4 *)(iVar1 + 0x38);
  local_c = 0xc;
  do {
    local_8 = (char *)puVar6;
    local_10 = _strlen((char *)puVar6[0xc]);
    sVar2 = _strlen((char *)*puVar6);
    puVar6 = (undefined4 *)((int)local_8 + 4);
    local_c = local_c + -1;
    iVar5 = sVar2 + iVar5 + 2 + local_10;
  } while (local_c != 0);
  local_8 = (char *)puVar6;
  pcVar3 = __malloc_crt(iVar5 + 1);
  local_8 = pcVar3;
  if (pcVar3 != (char *)0x0) {
    puVar6 = (undefined4 *)(iVar1 + 0x68);
    local_c = 0xc;
    do {
      *pcVar3 = ':';
      pcVar3 = pcVar3 + 1;
      eVar4 = _strcpy_s(pcVar3,(rsize_t)(local_8 + iVar5 + (1 - (int)pcVar3)),(char *)puVar6[-0xc]);
      if (eVar4 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      sVar2 = _strlen(pcVar3);
      pcVar3[sVar2] = ':';
      pcVar3 = pcVar3 + sVar2 + 1;
      eVar4 = _strcpy_s(pcVar3,(rsize_t)(local_8 + iVar5 + (1 - (int)pcVar3)),(char *)*puVar6);
      if (eVar4 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      sVar2 = _strlen(pcVar3);
      pcVar3 = pcVar3 + sVar2;
      puVar6 = puVar6 + 1;
      local_c = local_c + -1;
    } while (local_c != 0);
    *pcVar3 = '\0';
  }
  if (local_14 != '\0') {
    *(uint *)(local_18 + 0x70) = *(uint *)(local_18 + 0x70) & 0xfffffffd;
  }
  return local_8;
}

