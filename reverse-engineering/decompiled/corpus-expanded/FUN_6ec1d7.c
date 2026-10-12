/* Ghidra pseudocode, not original source.
 * ev_071b5a91353aec3b9b3ca880d0ad8ff1dbba963601d7a5f67d3b8ab6c7f681aa
 * Entry: 0x6ec1d7; label: _frexp
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _frexp
   
   Library: Visual Studio 2005 Release */

double __cdecl _frexp(double _X,int *_Y)

{
  double dVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  float10 fVar5;
  
  if (_Y == (int *)0x0) {
    puVar2 = (undefined4 *)FUN_006ead5f();
    *puVar2 = 0x16;
    FUN_006e9fc2();
    fVar5 = (float10)0;
    goto LAB_006ec2ad;
  }
  uVar3 = __ctrlfp(0x133f,0xffff);
  if ((_X._6_2_ & 0x7ff0) != 0x7ff0) {
    fVar5 = (float10)FUN_006f98f5(_X,_Y);
    __ctrlfp(uVar3,0xffff);
    fVar5 = (float10)(double)fVar5;
    goto LAB_006ec2ad;
  }
  *_Y = -1;
  iVar4 = __sptype(_X);
  if (iVar4 < 1) {
LAB_006ec268:
    dVar1 = _X + 1.0;
  }
  else {
    dVar1 = _DAT_00829f48;
    if (2 < iVar4) {
      if (iVar4 == 3) {
        fVar5 = (float10)__handle_qnan1();
        goto LAB_006ec2ad;
      }
      goto LAB_006ec268;
    }
  }
  fVar5 = (float10)__except1(8,0x17,_X,SUB84(dVar1,0),(int)((ulonglong)dVar1 >> 0x20),uVar3);
LAB_006ec2ad:
  return (double)fVar5;
}

