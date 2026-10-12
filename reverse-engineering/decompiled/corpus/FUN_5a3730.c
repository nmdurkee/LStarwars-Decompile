/* Ghidra analysis pseudocode, not original source.
 * ev_0b4f3bc8b4a39fc427a7fcc8ed3e1304ee3926d0e45102a57071cb05acfa7baa
 * Entry: 0x5a3730; label: FUN_005a3730
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a3730(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int *param_4,
                 undefined1 param_5,undefined4 param_6)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  bool bVar8;
  undefined1 local_30 [12];
  undefined1 local_24 [12];
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  puVar3 = DAT_0095da3c;
  puVar6 = (undefined4 *)*param_4;
  if ((undefined4 *)*param_4 == (undefined4 *)0x0) {
    if (DAT_0095da3c == (undefined4 *)0x0) {
      return;
    }
    puVar6 = (undefined4 *)*DAT_0095da3c;
    *DAT_0095da3c = DAT_0095da40;
    DAT_0095da3c = puVar6;
    if (DAT_0095da40 != (undefined4 *)0x0) {
      DAT_0095da40[1] = puVar3;
    }
    puVar3[1] = 0;
    DAT_0095da40 = puVar3;
    puVar3[2] = 0;
    if (puVar3 == (undefined4 *)0x0) {
      return;
    }
    puVar3[5] = param_4;
    *param_4 = (int)puVar3;
    puVar3[6] = param_3;
    *(undefined1 *)((int)puVar3 + 0xe) = param_5;
    puVar3[7] = param_6;
    puVar6 = puVar3;
  }
  piVar1 = DAT_0095da38;
  bVar8 = DAT_0095da38 != (int *)0x0;
  puVar6[4] = 1;
  puVar6[6] = param_3;
  if (bVar8) {
    DAT_0095da38 = (int *)*piVar1;
    iVar7 = puVar6[2];
    *piVar1 = iVar7;
    if (iVar7 != 0) {
      *(int **)(iVar7 + 4) = piVar1;
    }
    piVar1[1] = 0;
    puVar6[2] = piVar1;
  }
  iVar7 = puVar6[2];
  if (iVar7 != 0) {
    *(undefined4 *)(iVar7 + 8) = *param_1;
    *(undefined4 *)(iVar7 + 0xc) = param_1[1];
    *(undefined4 *)(iVar7 + 0x10) = param_1[2];
    iVar7 = puVar6[2];
    *(undefined4 *)(iVar7 + 0x14) = param_1[3];
    *(undefined4 *)(iVar7 + 0x18) = param_1[4];
    *(undefined4 *)(iVar7 + 0x1c) = param_1[5];
    *(undefined4 *)(puVar6[2] + 0xe4) = param_2;
    piVar1 = (int *)puVar6[2];
    if (*piVar1 != 0) {
      FUN_005b3800(piVar1 + 8,*piVar1 + 8,piVar1 + 2);
      piVar1 = (int *)puVar6[2];
      FUN_005b3800(piVar1 + 0xb,*piVar1 + 0x14,piVar1 + 5);
      FUN_005b3830(puVar6[2] + 0x20,puVar6[2] + 0x20,0x3eaaaaab);
      FUN_005b3830(puVar6[2] + 0x2c,puVar6[2] + 0x2c,0x3eaaaaab);
      piVar1 = *(int **)puVar6[2];
      piVar4 = (int *)puVar6[2] + 2;
      if (*piVar1 == 0) {
        FUN_005b3800(piVar1 + 8,piVar1 + 2,piVar4);
        iVar7 = *(int *)puVar6[2];
        FUN_005b3800(iVar7 + 0x2c,iVar7 + 0x14,(int *)puVar6[2] + 5);
        FUN_005b3830(*(int *)puVar6[2] + 0x20,*(int *)puVar6[2] + 0x20,0x3eaaaaab);
        FUN_005b3830(*(int *)puVar6[2] + 0x2c,*(int *)puVar6[2] + 0x2c,0x3eaaaaab);
      }
      else {
        iVar7 = *piVar1;
        FUN_005b3800(local_24,piVar1 + 2,piVar4);
        FUN_005b3800(local_30,iVar7 + 8,piVar1 + 2);
        FUN_005b3860(*(int *)puVar6[2] + 0x20,local_24,local_30,0x3f000000);
        piVar1 = *(int **)puVar6[2];
        iVar7 = *piVar1;
        piVar1 = piVar1 + 5;
        FUN_005b3800(local_24,piVar1,(int *)puVar6[2] + 5);
        FUN_005b3800(local_30,iVar7 + 0x14,piVar1);
        FUN_005b3860(*(int *)puVar6[2] + 0x2c,local_24,local_30,0x3f000000);
        FUN_005b3830(*(int *)puVar6[2] + 0x20,*(int *)puVar6[2] + 0x20,0x3eaaaaab);
        FUN_005b3830(*(int *)puVar6[2] + 0x2c,*(int *)puVar6[2] + 0x2c,0x3eaaaaab);
        param_4 = (int *)0x1;
        if (1 < *(int *)(**(int **)puVar6[2] + 0xe0)) {
          iVar7 = 0xc;
          do {
            iVar2 = **(int **)puVar6[2];
            FUN_005a35f0(iVar2 + 0x2c + iVar7,*(int **)puVar6[2] + 8,iVar2 + 0x20,0,1,
                         (1.0 / (float)*(int *)(iVar2 + 0xe0)) * (float)(int)param_4);
            iVar2 = **(int **)puVar6[2];
            FUN_005a35f0(iVar2 + 0x80 + iVar7,*(int **)puVar6[2] + 0xb,iVar2 + 0x2c,0,1,
                         (1.0 / (float)*(int *)(iVar2 + 0xe0)) * (float)(int)param_4);
            param_4 = (int *)((int)param_4 + 1);
            iVar7 = iVar7 + 0xc;
          } while ((int)param_4 < *(int *)(**(int **)puVar6[2] + 0xe0));
        }
      }
      FUN_005b3800(local_18,puVar6[2] + 0x14,puVar6[2] + 8);
      FUN_005b3800(local_c,*(int *)puVar6[2] + 0x14,*(int *)puVar6[2] + 8);
      FUN_005b3b30(local_18,local_18);
      FUN_005b3b30(local_c,local_c);
      uVar5 = FUN_006e6b90();
      *(undefined4 *)(*(int *)puVar6[2] + 0xe0) = uVar5;
      param_4 = (int *)0x1;
      if (1 < *(int *)(*(int *)puVar6[2] + 0xe0)) {
        iVar7 = 0xc;
        do {
          iVar2 = *(int *)puVar6[2];
          FUN_005a35f0(iVar2 + 0x2c + iVar7,(int *)puVar6[2] + 8,iVar2 + 0x20,0,1,
                       (1.0 / (float)*(int *)(iVar2 + 0xe0)) * (float)(int)param_4);
          iVar2 = *(int *)puVar6[2];
          FUN_005a35f0(iVar2 + 0x80 + iVar7,(int *)puVar6[2] + 0xb,iVar2 + 0x2c,0,1,
                       (1.0 / (float)*(int *)(iVar2 + 0xe0)) * (float)(int)param_4);
          param_4 = (int *)((int)param_4 + 1);
          iVar7 = iVar7 + 0xc;
        } while ((int)param_4 < *(int *)(*(int *)puVar6[2] + 0xe0));
      }
    }
  }
  return;
}

