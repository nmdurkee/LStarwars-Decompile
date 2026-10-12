/* Ghidra analysis pseudocode, not original source.
 * ev_aee1a4f0943f0e53edaf0cbac59fb891b878b74e3aefed4690394b4ea17c7eca
 * Entry: 0x70b099; label: __Getdays_l
 */

/* Library Function - Single Match
    __Getdays_l
   
   Library: Visual Studio 2005 Release */

char * __Getdays_l(localeinfo_struct *param_1)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  errno_t eVar4;
  int iVar5;
  int iVar6;
  int local_1c [2];
  int local_14;
  char local_10;
  char *local_c;
  uint local_8;
  
  iVar5 = 0;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_1c,param_1);
  iVar1 = *(int *)(local_1c[0] + 0xd4);
  local_8 = 0;
  do {
    iVar6 = local_8 * 4;
    local_c = (char *)_strlen(*(char **)(iVar6 + 0x1c + iVar1));
    sVar2 = _strlen(*(char **)(iVar6 + iVar1));
    local_8 = local_8 + 1;
    iVar5 = sVar2 + iVar5 + 2 + (int)local_c;
  } while (local_8 < 7);
  pcVar3 = __malloc_crt(iVar5 + 1);
  local_c = pcVar3;
  if (pcVar3 != (char *)0x0) {
    local_8 = 0;
    do {
      *pcVar3 = ':';
      pcVar3 = pcVar3 + 1;
      eVar4 = _strcpy_s(pcVar3,(rsize_t)(local_c + iVar5 + (1 - (int)pcVar3)),
                        *(char **)(iVar1 + local_8 * 4));
      if (eVar4 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      sVar2 = _strlen(pcVar3);
      pcVar3[sVar2] = ':';
      pcVar3 = pcVar3 + sVar2 + 1;
      eVar4 = _strcpy_s(pcVar3,(rsize_t)(local_c + iVar5 + (1 - (int)pcVar3)),
                        *(char **)(iVar1 + 0x1c + local_8 * 4));
      if (eVar4 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      sVar2 = _strlen(pcVar3);
      pcVar3 = pcVar3 + sVar2;
      local_8 = local_8 + 1;
    } while (local_8 < 7);
    *pcVar3 = '\0';
  }
  if (local_10 != '\0') {
    *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
  }
  return local_c;
}

