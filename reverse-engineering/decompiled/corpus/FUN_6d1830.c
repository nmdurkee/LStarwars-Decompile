/* Ghidra analysis pseudocode, not original source.
 * ev_b8d156e74790e07078a260599393ca89d6d858c624833fd21a4e8cf1d6239801
 * Entry: 0x6d1830; label: FUN_006d1830
 */

void FUN_006d1830(undefined4 param_1,int *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 *puStack_1c;
  undefined4 uStack_18;
  undefined4 local_c [3];
  
  uStack_18 = 0x14;
  puStack_1c = (undefined4 *)0x6d1842;
  puVar1 = (undefined4 *)FUN_00633440();
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &PTR_LAB_0076f960;
    puVar1[4] = 0;
    uStack_18 = 0;
    puStack_1c = local_c;
    puVar1[2] = param_2;
    puVar1[3] = param_3;
    (**(code **)(*param_2 + 4))(param_3,DAT_02973acc);
    pcVar2 = (char *)FUN_005cfa50(&puStack_1c);
    if (pcVar2 == (char *)0x0) {
      pcVar2 = "no name";
    }
    uVar3 = FUN_00626250(puVar1,&DAT_0081f9a0,&LAB_006cf8e0,FUN_006bf010,&LAB_006bf160,1,param_2[4],
                         pcVar2);
    puVar1[1] = uVar3;
    FUN_00618e10(local_c[0],uVar3);
  }
  return;
}

