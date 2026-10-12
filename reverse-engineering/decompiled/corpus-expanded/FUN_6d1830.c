/* Ghidra pseudocode, not original source.
 * ev_2fc6966d7cb88e652aff05d91af92c1aae7a14fbd03261d64dee7cfe7594468f
 * Entry: 0x6d1830; label: FUN_006d1830
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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
    *puVar1 = &PTR_FUN_0076f960;
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
    uVar3 = FUN_00626250(puVar1,&DAT_0081f9a0,FUN_006cf8e0,FUN_006bf010,FUN_006bf160,1,param_2[4],
                         pcVar2);
    puVar1[1] = uVar3;
    FUN_00618e10(local_c[0],uVar3);
  }
  return;
}

