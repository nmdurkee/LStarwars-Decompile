/* Ghidra analysis pseudocode, not original source.
 * ev_8191aeb1a3da19da8f7480131ae46b5e7aabe132901fddc0002d6d5d4eb98622
 * Entry: 0x48abf0; label: FUN_0048abf0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048abf0(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  FUN_00589ac0(1,&PTR_s_variant_00751d9f_1_007f1724);
  FUN_00414400();
  DAT_029130ec = (uint)(DAT_009553cc == 0);
  FUN_0062d540(&DAT_007f1b4c,1,&DAT_00924878,DAT_0092487c,1);
  FUN_00594600(&PTR_LAB_0075a180,0,&DAT_00855f0c,0xf,_DAT_00804fac);
  FUN_00594640("Characters",&DAT_008807b8,&DAT_00855ea4,0,0x4002000,0,0,0x16,&DAT_00924878,
               &DAT_0092487c,0,0x3f03d70a);
  FUN_00594640("Vehicles",0,&DAT_00855ed0,0x2000,0x4000000,0,0,7,&DAT_00924878,&DAT_0092487c,0,
               _DAT_00804fac);
  FUN_00594640("Minikits",0,&DAT_00855f24,0x4000000,0,0,0,0xc,&DAT_00924878,&DAT_0092487c,0,
               _DAT_00804fac);
  FUN_00594640(&DAT_0075a150,0,&DAT_00855ef8,0,0,0,1,10,&DAT_00924878,&DAT_0092487c,0,_DAT_00804fac)
  ;
  FUN_00594640(&DAT_00751ee8,&DAT_00881130,&DAT_00855ee4,8,0,0,0,7,&DAT_00924878,&DAT_0092487c,0,
               _DAT_00804fac);
  FUN_00594640("BlasterZipUps",&DAT_008807bc,&DAT_00855f58,0x100080,0x1000000,0,0,0xb,&DAT_00924878,
               &DAT_0092487c,0,_DAT_00804fac);
  FUN_00594640("BountyHunters",&DAT_00880788,&DAT_00855eb8,0x1000000,0,0,0,4,&DAT_00924878,
               &DAT_0092487c,0,_DAT_00804fac);
  FUN_00573240(&DAT_00924878,&DAT_0092487c);
  DAT_00856980 = FUN_005939a0("chars\\customiser.txt",&DAT_00924878,&DAT_0092487c,(int)DAT_007f18e4,
                              (int)DAT_007f18e8,&LAB_00423fa0,&LAB_00423b70,FUN_0057a240,
                              &DAT_0086e4ec,&PTR_DAT_007f37e0);
  FUN_0058abf0("chars\\specialmoves.txt",&DAT_00924878,&DAT_0092487c);
  iVar4 = 0;
  if (0 < DAT_00951b84) {
    iVar3 = 0;
    do {
      if ((*(uint *)(iVar3 + 100 + DAT_00951b78) & 0x400) != 0) {
        uVar1 = FUN_00548a60("statusscreen",DAT_009248cc,0xffffffff);
        *(undefined2 *)(iVar3 + 0x94 + DAT_00951b78) = uVar1;
        uVar2 = FUN_00694320(1,"statusscreen");
        *(undefined4 *)(iVar3 + 0x11c + DAT_00951b78) = uVar2;
        *(undefined4 *)(iVar3 + 0x118 + DAT_00951b78) =
             *(undefined4 *)(iVar3 + 0x11c + DAT_00951b78);
        uVar2 = FUN_00694320(2,"statusscreen");
        *(undefined4 *)(iVar3 + 0x124 + DAT_00951b78) = uVar2;
        *(undefined4 *)(iVar3 + 0x120 + DAT_00951b78) =
             *(undefined4 *)(iVar3 + 0x124 + DAT_00951b78);
        uVar2 = FUN_00694320(0x20,"statusscreen");
        *(undefined4 *)(iVar3 + 300 + DAT_00951b78) = uVar2;
        *(undefined4 *)(iVar3 + 0x128 + DAT_00951b78) = *(undefined4 *)(iVar3 + 300 + DAT_00951b78);
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x130;
    } while (iVar4 < DAT_00951b84);
  }
  return;
}

