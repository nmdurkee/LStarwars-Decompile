/* Ghidra analysis pseudocode, not original source.
 * ev_8191aeb1a3da19da8f7480131ae46b5e7aabe132901fddc0002d6d5d4eb98622
 * Entry: 0x48a6a0; label: FUN_0048a6a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048a6a0(void)

{
  uint *puVar1;
  undefined2 uVar2;
  undefined1 extraout_AH;
  int iVar3;
  undefined **ppuVar4;
  undefined1 local_904 [256];
  undefined1 local_804 [2048];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_904;
  FUN_00635a70(&DAT_00924878,DAT_009248ac,0x40);
  DAT_00924878 = DAT_00924878 + 3 & 0xfffffffc;
  FUN_00683530(&DAT_00924878,DAT_0092487c,"stuff\\particle",0x100,0x200,0x200);
  FUN_00658590(&DAT_00973718);
  if (DAT_00947bbc != 0) {
    FUN_0065e040(&DAT_00924878,DAT_0092487c,0x200,0x20,0x40);
  }
  DAT_0087b2d8 = FUN_005e4d20(1,10);
  *(undefined4 *)(DAT_0087b2d8 + 0x5c) = 0x3f800000;
  *(undefined4 *)(DAT_0087b2d8 + 0x58) = 0x3f800000;
  *(undefined4 *)(DAT_0087b2d8 + 0x54) = 0x3f800000;
  *(uint *)(DAT_0087b2d8 + 0x40) = *(uint *)(DAT_0087b2d8 + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_0087b2d8 + 0x40) = *(uint *)(DAT_0087b2d8 + 0x40) & 0xffff7fff | 0x4000;
  *(uint *)(DAT_0087b2d8 + 0x40) = *(uint *)(DAT_0087b2d8 + 0x40) & 0xffffffdf | 0x10;
  *(undefined4 *)(DAT_0087b2d8 + 0x70) = 0x3f7fbe77;
  *(uint *)(DAT_0087b2d8 + 0x40) = *(uint *)(DAT_0087b2d8 + 0x40) & 0xfffffff2 | 2;
  *(uint *)(DAT_0087b2d8 + 0x40) = *(uint *)(DAT_0087b2d8 + 0x40) & 0xfffffdff | 0x100;
  *(uint *)(DAT_0087b2d8 + 0x40) = *(uint *)(DAT_0087b2d8 + 0x40) & 0xfffff7ff | 0x400;
  *(undefined2 *)(DAT_0087b2d8 + 0x74) = *(undefined2 *)(DAT_0292fd60 + 0x74);
  *(uint *)(DAT_0087b2d8 + 0x44) = *(uint *)(DAT_0087b2d8 + 0x44) & 0xfffffffd | 1;
  FUN_005e4b00(DAT_0087b2d8);
  FUN_00609130(DAT_0087b2d8,0,0x3f010000,0x3e800000,0x3f100000);
  thunk_FUN_005f74a0();
  FUN_00543f30();
  FUN_0064a4b0(0x40,&DAT_00924878,&DAT_0092487c);
  FUN_0066b040();
  FUN_004f1f10(local_904,"stuff\\general.ptl");
  iVar3 = thunk_FUN_004fa610(local_904);
  if (iVar3 != 0) {
    DAT_00805b34 = FUN_0068df20(local_904,0,0);
  }
  FUN_004f1f10(local_904,"stuff\\char.ptl");
  iVar3 = thunk_FUN_004fa610(local_904);
  if (iVar3 != 0) {
    DAT_00805b38 = FUN_0068df20(local_904,5,0);
  }
  DAT_0093b0dc = FUN_0062c400(&DAT_00924878,&DAT_0092487c,400,0x93,&PTR_s_BULLET_SPARK_007f5dd0,0);
  DAT_00924878 = DAT_00924878 + 3 & 0xfffffffc;
  FUN_005a4160(&DAT_00924878,DAT_0092487c,"stuff\\streak.pnt");
  DAT_00924878 = DAT_00924878 + 3 & 0xfffffffc;
  FUN_004d7800(&DAT_0075a094,&DAT_00924878,&DAT_0092487c);
  FUN_005a2360(&DAT_00876688,&DAT_00924878,&DAT_0092487c,0x40);
  DAT_00924878 = DAT_00924878 + 0xff & 0xffffff00;
  DAT_00855f20 = FUN_005e4d40(1);
  *(undefined4 *)(DAT_00855f20 + 0x54) = 0x3f800000;
  *(undefined4 *)(DAT_00855f20 + 0x58) = 0x3f800000;
  *(undefined4 *)(DAT_00855f20 + 0x5c) = 0x3f800000;
  *(uint *)(DAT_00855f20 + 0x40) = *(uint *)(DAT_00855f20 + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_00855f20 + 0x40) = *(uint *)(DAT_00855f20 + 0x40) & 0xffff7fff | 0x4000;
  *(undefined4 *)(DAT_00855f20 + 0x70) = 0x3f7fbe77;
  *(uint *)(DAT_00855f20 + 0x40) = *(uint *)(DAT_00855f20 + 0x40) & 0xfffffff1 | 1;
  *(uint *)(DAT_00855f20 + 0x40) = *(uint *)(DAT_00855f20 + 0x40) & 0xff9fffff | 0x100000;
  *(undefined2 *)(DAT_00855f20 + 0x76) = 0xff;
  *(uint *)(DAT_00855f20 + 0x40) = *(uint *)(DAT_00855f20 + 0x40) & 0xfffeffff | 0x20000;
  uVar2 = FUN_005f8d60("stuff\\gradient",&DAT_00924878,DAT_0092487c);
  *(undefined2 *)(DAT_00855f20 + 0x74) = uVar2;
  FUN_005e4b00(DAT_00855f20);
  iVar3 = 0;
  do {
    FUN_0054fa60();
    local_804[iVar3] = extraout_AH;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x800);
  thunk_FUN_005f74a0(local_804);
  FUN_00564570();
  FUN_00553380();
  FUN_0065ee90();
  FUN_0065a510();
  FUN_005d1860();
  if (DAT_007f39e4 == 0) {
    ppuVar4 = &PTR_DAT_007f5c68;
  }
  else {
    ppuVar4 = &PTR_s_arrow_007f5c78;
  }
  FUN_005529f0(ppuVar4);
  DAT_00924878 = DAT_00924878 + 3 & 0xfffffffc;
  DAT_00924880 = FUN_005ef7f0(&DAT_00924878,DAT_0092487c,"stuff\\things.gsc");
  if (DAT_00924880 != 0) {
    FUN_0065b7f0(DAT_00924880);
    if (*(int *)(DAT_00924880 + 0x110) != 0) {
      puVar1 = (uint *)(*(int *)(DAT_00924880 + 0x110) + 0x74);
      *puVar1 = *puVar1 | 0x10;
    }
  }
  _DAT_00924884 =
       FUN_0066b8c0(0xffffffff,&DAT_00924878,DAT_0092487c,0,"stuff\\things",DAT_00924880,0,0x14,0x14
                    ,0x14);
  FUN_0066c810("stuff\\things",&DAT_00924884);
  if (DAT_007f39e4 != 0) {
    FUN_00564a20("stuff\\starfield.gsc",&DAT_00924878,&DAT_0092487c);
  }
  FUN_005e4e80(0xf);
  FUN_006489c0(DAT_00805b34);
  FUN_004f1f10(local_904,"stuff\\general.par");
  iVar3 = thunk_FUN_004fa610(local_904);
  if (iVar3 != 0) {
    _DAT_00803444 = FUN_0064c6c0(local_904,0,DAT_00924880);
  }
  FUN_005e4e80(0);
  FUN_0052c6d0("scripts",&DAT_00924878,&DAT_0092487c,0);
  __security_check_cookie(local_4 ^ (uint)local_904);
  return;
}

