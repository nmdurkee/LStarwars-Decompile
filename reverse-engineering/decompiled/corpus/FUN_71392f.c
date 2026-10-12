/* Ghidra analysis pseudocode, not original source.
 * ev_7b35a8fafa232ee0b9a0913c200a618a9d6b1b7e21f700964d68a0258798e3f5
 * Entry: 0x71392f; label: __isindst_nolock
 */

/* Library Function - Single Match
    __isindst_nolock
   
   Library: Visual Studio 2005 Release */

bool __isindst_nolock(void)

{
  bool bVar1;
  errno_t eVar2;
  int iVar3;
  int *unaff_EDI;
  int iVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  int local_8;
  
  local_8 = 0;
  eVar2 = __get_daylight(&local_8);
  if (eVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  if (local_8 == 0) {
    return false;
  }
  iVar4 = unaff_EDI[5];
  if ((iVar4 != DAT_0082ab20) || (iVar4 != DAT_0082ab2c)) {
    if (DAT_0297cc54 == 0) {
      cvtdate(1,1,iVar4,1,0,0,0,0,0);
      cvtdate(0,1,unaff_EDI[5],5,0,0,0,0,0);
    }
    else {
      if (DAT_0297cc40 != 0) {
        uVar6 = 0;
        uVar5 = 0;
        uVar7 = DAT_0297cc46;
      }
      else {
        uVar6 = DAT_0297cc44;
        uVar5 = DAT_0297cc46;
        uVar7 = 0;
      }
      cvtdate(1,DAT_0297cc40 == 0,iVar4,uVar5,uVar6,uVar7,DAT_0297cc4a,DAT_0297cc4c,DAT_0297cc4e);
      if (DAT_0297cbec != 0) {
        uVar6 = 0;
        uVar5 = 0;
        iVar4 = unaff_EDI[5];
        uVar7 = DAT_0297cbf2;
      }
      else {
        iVar4 = unaff_EDI[5];
        uVar6 = DAT_0297cbf0;
        uVar5 = DAT_0297cbf2;
        uVar7 = 0;
      }
      cvtdate(0,DAT_0297cbec == 0,iVar4,uVar5,uVar6,uVar7,DAT_0297cbf6,DAT_0297cbf8,DAT_0297cbfa);
    }
  }
  iVar4 = unaff_EDI[7];
  if (DAT_0082ab24 < DAT_0082ab30) {
    if ((iVar4 < DAT_0082ab24) || (DAT_0082ab30 < iVar4)) {
      return false;
    }
    if ((DAT_0082ab24 < iVar4) && (iVar4 < DAT_0082ab30)) {
      return true;
    }
  }
  else {
    if (iVar4 < DAT_0082ab30) {
      return true;
    }
    if (DAT_0082ab24 < iVar4) {
      return true;
    }
    if ((DAT_0082ab30 < iVar4) && (iVar4 < DAT_0082ab24)) {
      return false;
    }
  }
  iVar3 = ((unaff_EDI[2] * 0x3c + unaff_EDI[1]) * 0x3c + *unaff_EDI) * 1000;
  if (iVar4 == DAT_0082ab24) {
    bVar1 = DAT_0082ab28 <= iVar3;
  }
  else {
    bVar1 = iVar3 < DAT_0082ab34;
  }
  return bVar1;
}

