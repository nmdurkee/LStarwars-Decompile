/* Ghidra pseudocode, not original source.
 * ev_ab45728ea6dd43502824c472d7f84a4237b6985bbd98dd18e4509cbe0b313452
 * Entry: 0x696d00; label: FUN_00696d00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00696d00(undefined4 param_1,undefined1 param_2,undefined1 param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  int *piStack_40;
  int iStack_3c;
  int *piStack_38;
  undefined4 *puStack_34;
  int *piStack_30;
  undefined4 uStack_2c;
  undefined4 *puStack_28;
  
  puVar1 = (undefined4 *)(in_ECX + 0xd18);
  uStack_2c = 0;
  *(undefined1 *)(in_ECX + 5) = param_2;
  *(undefined1 *)(in_ECX + 6) = param_3;
  piStack_30 = (int *)0x696d26;
  puStack_28 = puVar1;
  iVar4 = DirectSoundCreate8();
  if (-1 < iVar4) {
    piStack_30 = (int *)*puVar1;
    puStack_28 = (undefined4 *)0x2;
    uStack_2c = DAT_00924864;
    puStack_34 = (undefined4 *)0x696d42;
    (**(code **)(*piStack_30 + 0x18))();
    piStack_38 = (int *)*puVar1;
    puStack_34 = (undefined4 *)(in_ECX + 0xd1c);
    *puStack_34 = 0x60;
    iStack_3c = 0x696d59;
    (**(code **)(*piStack_38 + 0x10))();
    piStack_40 = (int *)*puVar1;
    iStack_3c = in_ECX + 0xd7c;
    (**(code **)(*piStack_40 + 0x20))();
    *(undefined4 *)(in_ECX + 0xd88) = 0;
    *(undefined4 *)(in_ECX + 0xd8c) = 0;
    *(undefined4 *)(in_ECX + 0xd90) = 0;
    *(undefined4 *)(in_ECX + 0xd94) = 0;
    *(undefined4 *)(in_ECX + 0xd98) = 0;
    *(undefined4 *)(in_ECX + 0xd9c) = 0;
    *(undefined4 *)(in_ECX + 0xda0) = 0;
    *(undefined4 *)(in_ECX + 0xda4) = 0;
    piVar2 = (int *)(in_ECX + 0xd80);
    *(undefined4 *)(in_ECX + 0xd84) = 0x24;
    *(undefined4 *)(in_ECX + 0xd8c) = 0;
    *(undefined4 *)(in_ECX + 0xd94) = 0;
    *(undefined4 *)(in_ECX + 0xd88) = 0x11;
    (**(code **)(*(int *)*puVar1 + 0xc))((int *)*puVar1,(undefined4 *)(in_ECX + 0xd84),piVar2,0);
    piVar3 = (int *)*piVar2;
    if (piVar3 != (int *)0x0) {
      piStack_40 = (int *)0x20001;
      iStack_3c = 0xac44;
      puStack_34 = (undefined4 *)0x100004;
      piStack_38 = (int *)0x2b110;
      piStack_30 = (int *)((uint)piStack_30 & 0xffff0000);
      (**(code **)(*piVar3 + 0x38))(piVar3,&piStack_40);
    }
    (*(code *)**(undefined4 **)*piVar2)((undefined4 *)*piVar2,&DAT_0078494c,&DAT_02972c34);
    if (DAT_02972c34 != (int *)0x0) {
      (**(code **)(*DAT_02972c34 + 0x38))(DAT_02972c34,0,0,0,1);
      (**(code **)(*DAT_02972c34 + 0x34))(DAT_02972c34,0,0,0x3f800000,0,0x3f800000,0,1);
      (**(code **)(*DAT_02972c34 + 0x3c))(DAT_02972c34,0,1);
      (**(code **)(*DAT_02972c34 + 0x44))(DAT_02972c34);
    }
    _memset((void *)(in_ECX + 0xc),0,0xd00);
    iVar4 = FUN_006ea018(0x400);
    if (iVar4 == 0) {
      DAT_02972c00 = 0;
    }
    else {
      DAT_02972c00 = FUN_00699ec0(DAT_02973960,6);
    }
    iVar4 = FUN_006ea018(0x400);
    if (iVar4 != 0) {
      DAT_02972c04 = FUN_00699ec0(DAT_02973960,6);
      return;
    }
    DAT_02972c04 = 0;
  }
  return;
}

