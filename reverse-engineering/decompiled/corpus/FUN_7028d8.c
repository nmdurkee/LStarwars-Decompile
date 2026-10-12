/* Ghidra analysis pseudocode, not original source.
 * ev_8dba402bb7d22455a765fa1be408776d0f2383442396bc16910bcc92f9a08d40
 * Entry: 0x7028d8; label: UnDecorator::getTypeEncoding
 */

/* WARNING: Removing unreachable block (ram,0x00702c82) */
/* WARNING: Removing unreachable block (ram,0x00702b22) */
/* WARNING: Removing unreachable block (ram,0x00702c97) */
/* WARNING: Removing unreachable block (ram,0x00702c48) */
/* WARNING: Removing unreachable block (ram,0x00702c0e) */
/* WARNING: Removing unreachable block (ram,0x00702c23) */
/* WARNING: Removing unreachable block (ram,0x00702c5d) */
/* Library Function - Single Match
    private: static int __cdecl UnDecorator::getTypeEncoding(void)
   
   Library: Visual Studio 2005 Release */

int __cdecl UnDecorator::getTypeEncoding(void)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  
  do {
    uVar3 = 0;
    if (*DAT_0297cb78 == '_') {
      DAT_0297cb78 = DAT_0297cb78 + 1;
      uVar3 = 0x4000;
    }
    cVar1 = *DAT_0297cb78;
    if (('@' < cVar1) && (cVar1 < '[')) {
      uVar7 = (int)*DAT_0297cb78 - 0x41;
      DAT_0297cb78 = DAT_0297cb78 + 1;
      if ((uVar7 & 1) == 0) {
        uVar3 = uVar3 | 0x8000;
      }
      else {
        uVar3 = uVar3 | 0xa000;
      }
      if (0x17 < (int)uVar7) {
        return uVar3;
      }
      if ((uVar3 & 0x8000) == 0) {
        uVar3 = uVar3 & 0xffff9fff;
      }
      else {
        uVar3 = uVar3 | 0x800;
      }
      uVar6 = uVar7 & 0x18;
      if (uVar6 == 0) {
        if ((uVar3 & 0x8000) == 0) {
          uVar3 = uVar3 | 0x800;
        }
        else {
          uVar3 = uVar3 | 0x40;
        }
      }
      else if (uVar6 == 8) {
        if ((uVar3 & 0x8000) == 0) {
          uVar3 = uVar3 & 0xfffff7ff | 0x1000;
        }
        else {
          uVar3 = uVar3 | 0x80;
        }
      }
      else {
        if (uVar6 != 0x10) {
          return 0xffff;
        }
        if ((uVar3 & 0x8000) == 0) {
          uVar3 = uVar3 & 0xffffe7ff;
        }
      }
      uVar7 = uVar7 & 6;
      if (uVar7 != 0) {
        if (uVar7 == 2) {
          if ((uVar3 & 0x8000) == 0) {
            return uVar3 & 0xffff9fff;
          }
          return uVar3 | 0x200;
        }
        if (uVar7 != 4) {
          if (uVar7 != 6) {
            return 0xffff;
          }
          return uVar3 | 0x400;
        }
        return uVar3 | 0x100;
      }
      return uVar3;
    }
    if (cVar1 != '$') {
      cVar1 = *DAT_0297cb78;
      if (('/' < cVar1) && (cVar1 < '9')) {
        DAT_0297cb78 = DAT_0297cb78 + 1;
        switch(cVar1) {
        case '0':
          return 0x800;
        case '1':
          return 0x1000;
        case '2':
          return 0;
        case '3':
          return 0x4000;
        case '4':
          return 0x2000;
        case '5':
          return 0x6000;
        case '6':
          return 0x6800;
        case '7':
          return 0x7000;
        case '8':
          return 0x7800;
        default:
          return 0xffff;
        }
      }
      if (cVar1 != '9') {
        return (cVar1 != '\0') + 0xfffe;
      }
      DAT_0297cb78 = DAT_0297cb78 + 1;
      return 0xfffd;
    }
    bVar2 = false;
    pcVar4 = DAT_0297cb78 + 1;
    cVar1 = *pcVar4;
    if ('B' < cVar1) {
      if (cVar1 == 'C') {
        uVar3 = 0x7c00;
      }
      else if (cVar1 == 'D') {
        uVar3 = uVar3 | 0x9100;
      }
      else if (cVar1 == 'E') {
        uVar3 = uVar3 | 0x9200;
      }
      else {
        if (cVar1 != 'R') {
          DAT_0297cb78 = pcVar4;
          return 0xffff;
        }
        pcVar4 = DAT_0297cb78 + 2;
        bVar2 = true;
LAB_00702b01:
        if (bVar2) {
          uVar3 = uVar3 | 0x8e00;
        }
        else {
          uVar3 = uVar3 | 0x8d00;
        }
        if (((int)*pcVar4 - 0x30U & 1) != 0) {
          uVar3 = uVar3 | 0x2000;
        }
        uVar7 = (int)*pcVar4 - 0x30U & 6;
        if (uVar7 == 0) {
          if ((uVar3 & 0x8000) == 0) {
            uVar3 = uVar3 | 0x800;
          }
          else {
            uVar3 = uVar3 | 0x40;
          }
        }
        else if (uVar7 == 2) {
          if ((uVar3 & 0x8000) == 0) {
            uVar3 = uVar3 & 0xfffff7ff | 0x1000;
          }
          else {
            uVar3 = uVar3 | 0x80;
          }
        }
        else {
          if (uVar7 != 4) {
            DAT_0297cb78 = pcVar4;
            return 0xffff;
          }
          if ((uVar3 & 0x8000) == 0) {
            uVar3 = uVar3 & 0xffffe7ff;
          }
        }
      }
      goto switchD_0070295f_caseD_47;
    }
    if (cVar1 == 'B') {
      uVar3 = uVar3 | 0x9800;
      goto switchD_0070295f_caseD_47;
    }
    if (cVar1 == '\0') {
      uVar3 = 0xfffe;
      goto switchD_0070295f_caseD_47;
    }
    if (cVar1 != '$') {
      if (cVar1 < '0') {
        DAT_0297cb78 = pcVar4;
        return 0xffff;
      }
      if (cVar1 < '6') goto LAB_00702b01;
      if (cVar1 != 'A') {
        DAT_0297cb78 = pcVar4;
        return 0xffff;
      }
      uVar3 = uVar3 | 0x9000;
switchD_0070295f_caseD_47:
      DAT_0297cb78 = pcVar4 + 1;
      return uVar3;
    }
    pcVar5 = pcVar4;
    if (DAT_0297cb78[2] == 'P') {
      pcVar5 = DAT_0297cb78 + 2;
    }
    pcVar4 = pcVar5 + 1;
    switch(*pcVar4) {
    case 'F':
    case 'H':
    case 'L':
    case 'M':
    case 'Q':
      DAT_0297cb78 = pcVar5 + 2;
      break;
    default:
      goto switchD_0070295f_caseD_47;
    case 'J':
    case 'N':
    case 'O':
      pcVar4 = pcVar5 + 2;
      cVar1 = *pcVar4;
      if (('/' < cVar1) && (cVar1 < ':')) {
        DAT_0297cb78 = pcVar5 + cVar1 + -0x2d;
        uVar3 = getTypeEncoding();
        return uVar3 | 0x10000;
      }
      uVar3 = 0xffff;
      goto switchD_0070295f_caseD_47;
    }
  } while( true );
}

