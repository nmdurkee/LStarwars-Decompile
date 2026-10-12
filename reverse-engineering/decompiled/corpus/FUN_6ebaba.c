/* Ghidra analysis pseudocode, not original source.
 * ev_0c181eace2d19d4182fe88edb7c380dbd0b0bf6e152acc5799b1564533e0f6fc
 * Entry: 0x6ebaba; label: _ldexp
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _ldexp
   
   Library: Visual Studio 2005 Release */

double __cdecl _ldexp(double _X,int _Y)

{
  undefined4 uVar1;
  int iVar2;
  float10 fVar3;
  double dVar4;
  undefined4 uVar5;
  int local_8;
  
  uVar1 = __ctrlfp(0x133f,0xffff);
  if ((_X._6_2_ & 0x7ff0) == 0x7ff0) {
    iVar2 = __sptype(_X);
    if (0 < iVar2) {
      if (iVar2 < 3) goto LAB_006ebb1e;
      if (iVar2 == 3) {
        fVar3 = (float10)__handle_qnan2();
        goto LAB_006ebc64;
      }
    }
    dVar4 = _X + 1.0;
    uVar5 = 8;
  }
  else {
    if (_X == 0.0) {
LAB_006ebb1e:
      __ctrlfp(uVar1,0xffff);
LAB_006ebc61:
      fVar3 = (float10)(double)CONCAT26(_X._6_2_,_X._0_6_);
      goto LAB_006ebc64;
    }
    fVar3 = (float10)FUN_006f98f5(_X,&local_8);
    if (_Y < 0) {
      if (local_8 < -0x80000000 - _Y) {
LAB_006ebc09:
        fVar3 = fVar3 * (float10)0.0;
LAB_006ebc0f:
        dVar4 = (double)fVar3;
        uVar5 = 0x12;
        goto LAB_006ebb4e;
      }
LAB_006ebb9d:
      local_8 = _Y + local_8;
      if (0xa00 < local_8) goto LAB_006ebba6;
      if (local_8 < 0x401) {
        if (local_8 < -0x9fd) goto LAB_006ebc09;
        if (-0x3fe < local_8) {
          fVar3 = (float10)__set_exp((double)fVar3,local_8);
          _X._0_6_ = SUB86((double)fVar3,0);
          _X._6_2_ = (ushort)((ulonglong)(double)fVar3 >> 0x30);
          __ctrlfp(uVar1,0xffff);
          goto LAB_006ebc61;
        }
        fVar3 = (float10)__set_exp((double)fVar3,local_8 + 0x600);
        goto LAB_006ebc0f;
      }
      fVar3 = (float10)__set_exp((double)fVar3,local_8 + -0x600);
      dVar4 = (double)fVar3;
    }
    else {
      if (local_8 <= 0x7fffffff - _Y) goto LAB_006ebb9d;
LAB_006ebba6:
      dVar4 = __copysign(_DAT_00829f40,(double)fVar3);
    }
    uVar5 = 0x11;
  }
LAB_006ebb4e:
  fVar3 = (float10)__except2(uVar5,0x19,_X,(double)_Y,dVar4,uVar1);
LAB_006ebc64:
  return (double)fVar3;
}

