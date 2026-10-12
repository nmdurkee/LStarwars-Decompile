/* Ghidra analysis pseudocode, not original source.
 * ev_5fe54c2a55e5805f81bff5ddaf4fd9cf0184cfdba0adc5a7ca08f803c24de38d
 * Entry: 0x6ecda1; label: ___control87_2
 */

/* Library Function - Single Match
    ___control87_2
   
   Library: Visual Studio 2005 Release */

int __cdecl ___control87_2(uint _NewValue,uint _Mask,uint *_X86_cw,uint *_Sse2_cw)

{
  uint uVar1;
  undefined4 uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  ushort in_FPUControlWord;
  
  uVar4 = 0;
  if (_X86_cw != (uint *)0x0) {
    if ((in_FPUControlWord & 1) != 0) {
      uVar4 = 0x10;
    }
    if ((in_FPUControlWord & 4) != 0) {
      uVar4 = uVar4 | 8;
    }
    if ((in_FPUControlWord & 8) != 0) {
      uVar4 = uVar4 | 4;
    }
    if ((in_FPUControlWord & 0x10) != 0) {
      uVar4 = uVar4 | 2;
    }
    if ((in_FPUControlWord & 0x20) != 0) {
      uVar4 = uVar4 | 1;
    }
    if ((in_FPUControlWord & 2) != 0) {
      uVar4 = uVar4 | 0x80000;
    }
    uVar3 = in_FPUControlWord & 0xc00;
    if ((in_FPUControlWord & 0xc00) != 0) {
      if (uVar3 == 0x400) {
        uVar4 = uVar4 | 0x100;
      }
      else if (uVar3 == 0x800) {
        uVar4 = uVar4 | 0x200;
      }
      else if (uVar3 == 0xc00) {
        uVar4 = uVar4 | 0x300;
      }
    }
    if ((in_FPUControlWord & 0x300) == 0) {
      uVar4 = uVar4 | 0x20000;
    }
    else if ((in_FPUControlWord & 0x300) == 0x200) {
      uVar4 = uVar4 | 0x10000;
    }
    if ((in_FPUControlWord & 0x1000) != 0) {
      uVar4 = uVar4 | 0x40000;
    }
    uVar5 = ~_Mask & uVar4 | _NewValue & _Mask;
    if (uVar5 != uVar4) {
      uVar4 = __hw_cw();
      uVar5 = 0;
      if ((uVar4 & 1) != 0) {
        uVar5 = 0x10;
      }
      if ((uVar4 & 4) != 0) {
        uVar5 = uVar5 | 8;
      }
      if ((uVar4 & 8) != 0) {
        uVar5 = uVar5 | 4;
      }
      if ((uVar4 & 0x10) != 0) {
        uVar5 = uVar5 | 2;
      }
      if ((uVar4 & 0x20) != 0) {
        uVar5 = uVar5 | 1;
      }
      if ((uVar4 & 2) != 0) {
        uVar5 = uVar5 | 0x80000;
      }
      uVar1 = uVar4 & 0xc00;
      if (uVar1 != 0) {
        if (uVar1 == 0x400) {
          uVar5 = uVar5 | 0x100;
        }
        else if (uVar1 == 0x800) {
          uVar5 = uVar5 | 0x200;
        }
        else if (uVar1 == 0xc00) {
          uVar5 = uVar5 | 0x300;
        }
      }
      if ((uVar4 & 0x300) == 0) {
        uVar5 = uVar5 | 0x20000;
      }
      else if ((uVar4 & 0x300) == 0x200) {
        uVar5 = uVar5 | 0x10000;
      }
      if ((uVar4 & 0x1000) != 0) {
        uVar5 = uVar5 | 0x40000;
      }
    }
    *_X86_cw = uVar5;
  }
  if (_Sse2_cw != (uint *)0x0) {
    uVar4 = 0;
    if (DAT_029a9c48 == 0) {
      *_Sse2_cw = 0;
    }
    else {
      if ((char)MXCSR < '\0') {
        uVar4 = 0x10;
      }
      if ((MXCSR & 0x200) != 0) {
        uVar4 = uVar4 | 8;
      }
      if ((MXCSR & 0x400) != 0) {
        uVar4 = uVar4 | 4;
      }
      if ((MXCSR & 0x800) != 0) {
        uVar4 = uVar4 | 2;
      }
      if ((MXCSR & 0x1000) != 0) {
        uVar4 = uVar4 | 1;
      }
      if ((MXCSR & 0x100) != 0) {
        uVar4 = uVar4 | 0x80000;
      }
      uVar5 = MXCSR & 0x6000;
      if (uVar5 != 0) {
        if (uVar5 == 0x2000) {
          uVar4 = uVar4 | 0x100;
        }
        else if (uVar5 == 0x4000) {
          uVar4 = uVar4 | 0x200;
        }
        else if (uVar5 == 0x6000) {
          uVar4 = uVar4 | 0x300;
        }
      }
      uVar5 = MXCSR & 0x8040;
      if (uVar5 == 0x40) {
        uVar4 = uVar4 | 0x2000000;
      }
      else if (uVar5 == 0x8000) {
        uVar4 = uVar4 | 0x3000000;
      }
      else if (uVar5 == 0x8040) {
        uVar4 = uVar4 | 0x1000000;
      }
      if ((~(_Mask & 0x308031f) & uVar4 | _Mask & 0x308031f & _NewValue) != uVar4) {
        uVar2 = ___hw_cw_sse2();
        ___set_fpsr_sse2(uVar2);
        uVar4 = 0;
        if ((char)MXCSR < '\0') {
          uVar4 = 0x10;
        }
        if ((MXCSR & 0x200) != 0) {
          uVar4 = uVar4 | 8;
        }
        if ((MXCSR & 0x400) != 0) {
          uVar4 = uVar4 | 4;
        }
        if ((MXCSR & 0x800) != 0) {
          uVar4 = uVar4 | 2;
        }
        if ((MXCSR & 0x1000) != 0) {
          uVar4 = uVar4 | 1;
        }
        if ((MXCSR & 0x100) != 0) {
          uVar4 = uVar4 | 0x80000;
        }
        uVar5 = MXCSR & 0x6000;
        if (uVar5 != 0) {
          if (uVar5 == 0x2000) {
            uVar4 = uVar4 | 0x100;
          }
          else if (uVar5 == 0x4000) {
            uVar4 = uVar4 | 0x200;
          }
          else if (uVar5 == 0x6000) {
            uVar4 = uVar4 | 0x300;
          }
        }
        uVar5 = MXCSR & 0x8040;
        if (uVar5 == 0x40) {
          uVar4 = uVar4 | 0x2000000;
        }
        else if (uVar5 == 0x8000) {
          uVar4 = uVar4 | 0x3000000;
        }
        else if (uVar5 == 0x8040) {
          uVar4 = uVar4 | 0x1000000;
        }
      }
      *_Sse2_cw = uVar4;
    }
  }
  return 1;
}

