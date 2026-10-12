/* Ghidra analysis pseudocode, not original source.
 * ev_5fe54c2a55e5805f81bff5ddaf4fd9cf0184cfdba0adc5a7ca08f803c24de38d
 * Entry: 0x6ee305; label: __cftoa_l
 */

/* Library Function - Single Match
    __cftoa_l
   
   Library: Visual Studio 2005 Release */

errno_t __cftoa_l(double *param_1,undefined1 *param_2,uint param_3,size_t param_4,int param_5,
                 localeinfo_struct *param_6)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  errno_t *peVar4;
  size_t _SizeInBytes;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint extraout_ECX_01;
  undefined4 extraout_EDX;
  int iVar9;
  undefined4 extraout_EDX_00;
  short sVar10;
  char *pcVar11;
  char *pcVar12;
  bool bVar13;
  errno_t eVar14;
  int local_28 [2];
  int local_20;
  char local_1c;
  uint local_18;
  undefined4 local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  local_18 = 0x3ff;
  local_8 = 0x30;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_28,param_6);
  if ((int)param_4 < 0) {
    param_4 = 0;
  }
  if ((param_2 == (undefined1 *)0x0) || (param_3 == 0)) {
    peVar4 = (errno_t *)FUN_006ead5f();
    eVar14 = 0x16;
LAB_006ee33e:
    *peVar4 = eVar14;
    FUN_006e9fc2(0,0,0,0,0);
    if (local_1c != '\0') {
      *(uint *)(local_20 + 0x70) = *(uint *)(local_20 + 0x70) & 0xfffffffd;
    }
    return eVar14;
  }
  *param_2 = 0;
  if (param_3 <= param_4 + 0xb) {
    peVar4 = (errno_t *)FUN_006ead5f();
    eVar14 = 0x22;
    goto LAB_006ee33e;
  }
  local_10 = *(uint *)param_1;
  if ((*(uint *)((int)param_1 + 4) >> 0x14 & 0x7ff) == 0x7ff) {
    if (param_3 == 0xffffffff) {
      _SizeInBytes = 0xffffffff;
    }
    else {
      _SizeInBytes = param_3 - 2;
    }
    eVar14 = __cftoe(param_1,param_2 + 2,_SizeInBytes,param_4,0);
    if (eVar14 != 0) {
      *param_2 = 0;
      if (local_1c == '\0') {
        return eVar14;
      }
      *(uint *)(local_20 + 0x70) = *(uint *)(local_20 + 0x70) & 0xfffffffd;
      return eVar14;
    }
    if (param_2[2] == '-') {
      *param_2 = 0x2d;
      param_2 = param_2 + 1;
    }
    *param_2 = 0x30;
    param_2[1] = ((param_5 == 0) - 1U & 0xe0) + 0x78;
    pcVar5 = _strrchr(param_2 + 2,0x65);
    if (pcVar5 != (char *)0x0) {
      *pcVar5 = ((param_5 == 0) - 1U & 0xe0) + 0x70;
      pcVar5[3] = '\0';
    }
    goto LAB_006ee662;
  }
  if ((*(uint *)((int)param_1 + 4) & 0x80000000) != 0) {
    *param_2 = 0x2d;
    param_2 = param_2 + 1;
  }
  *param_2 = 0x30;
  param_2[1] = ((param_5 == 0) - 1U & 0xe0) + 0x78;
  sVar10 = (-(ushort)(param_5 != 0) & 0xffe0) + 0x27;
  if (((ulonglong)*param_1 & 0x7ff0000000000000) == 0) {
    param_2[2] = 0x30;
    if (*(int *)param_1 == 0 && ((ulonglong)*param_1 & 0xfffff00000000) == 0) {
      local_18 = 0;
    }
    else {
      local_18 = 0x3fe;
    }
  }
  else {
    param_2[2] = 0x31;
  }
  pcVar12 = param_2 + 3;
  pcVar5 = param_2 + 4;
  if (param_4 == 0) {
    *pcVar12 = '\0';
  }
  else {
    *pcVar12 = *(char *)**(undefined4 **)(local_28[0] + 0xbc);
  }
  if ((((ulonglong)*param_1 & 0xfffff00000000) != 0) || (local_c = 0, *(int *)param_1 != 0)) {
    local_10 = 0;
    local_c = 0xf0000;
    do {
      if ((int)param_4 < 1) break;
      sVar2 = __aullshr();
      uVar3 = sVar2 + 0x30;
      if (0x39 < uVar3) {
        uVar3 = uVar3 + sVar10;
      }
      local_8 = local_8 + -4;
      *pcVar5 = (char)uVar3;
      local_10 = local_10 >> 4 | local_c << 0x1c;
      local_c = local_c >> 4;
      pcVar5 = pcVar5 + 1;
      param_4 = param_4 - 1;
    } while (-1 < (short)local_8);
    if ((-1 < (short)local_8) && (uVar3 = __aullshr(), pcVar11 = pcVar5, 8 < uVar3)) {
      while( true ) {
        pcVar6 = pcVar11 + -1;
        if ((*pcVar6 != 'f') && (*pcVar6 != 'F')) break;
        *pcVar6 = '0';
        pcVar11 = pcVar6;
      }
      if (pcVar6 == pcVar12) {
        pcVar11[-2] = pcVar11[-2] + '\x01';
      }
      else if (*pcVar6 == '9') {
        *pcVar6 = (char)sVar10 + ':';
      }
      else {
        *pcVar6 = *pcVar6 + '\x01';
      }
    }
  }
  if (0 < (int)param_4) {
    _memset(pcVar5,0x30,param_4);
    pcVar5 = pcVar5 + param_4;
  }
  if (*pcVar12 == '\0') {
    pcVar5 = pcVar12;
  }
  *pcVar5 = ((param_5 == 0) - 1U & 0xe0) + 0x70;
  uVar7 = __aullshr();
  uVar8 = (uVar7 & 0x7ff) - local_18;
  iVar9 = -(uint)((uVar7 & 0x7ff) < local_18);
  if (iVar9 < 0) {
    pcVar5[1] = '-';
    bVar13 = uVar8 != 0;
    uVar8 = -uVar8;
    iVar9 = -(iVar9 + (uint)bVar13);
  }
  else {
    pcVar5[1] = '+';
  }
  pcVar11 = pcVar5 + 2;
  *pcVar11 = '0';
  pcVar12 = pcVar11;
  if ((iVar9 < 0) || ((iVar9 < 1 && (uVar8 < 1000)))) {
LAB_006ee611:
    if ((-1 < iVar9) && ((0 < iVar9 || (99 < uVar8)))) goto LAB_006ee61c;
  }
  else {
    cVar1 = __alldvrm(uVar8,iVar9,1000,0);
    *pcVar11 = cVar1 + '0';
    pcVar12 = pcVar5 + 3;
    iVar9 = 0;
    uVar8 = extraout_ECX;
    local_14 = extraout_EDX;
    if (pcVar12 == pcVar11) goto LAB_006ee611;
LAB_006ee61c:
    cVar1 = __alldvrm(uVar8,iVar9,100,0);
    *pcVar12 = cVar1 + '0';
    pcVar12 = pcVar12 + 1;
    iVar9 = 0;
    uVar8 = extraout_ECX_00;
    local_14 = extraout_EDX_00;
  }
  if ((pcVar12 != pcVar11) || ((-1 < iVar9 && ((0 < iVar9 || (9 < uVar8)))))) {
    cVar1 = __alldvrm(uVar8,iVar9,10,0);
    *pcVar12 = cVar1 + '0';
    pcVar12 = pcVar12 + 1;
    uVar8 = extraout_ECX_01;
  }
  *pcVar12 = (char)uVar8 + '0';
  pcVar12[1] = '\0';
LAB_006ee662:
  if (local_1c != '\0') {
    *(uint *)(local_20 + 0x70) = *(uint *)(local_20 + 0x70) & 0xfffffffd;
  }
  return 0;
}

