/* Ghidra pseudocode, not original source.
 * ev_c80330773f662e8a33570a4ca58388b0b4349f11aa110fb6d722955620f1df5d
 * Entry: 0x631440; label: FUN_00631440
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00631440(int param_1)

{
  int *piVar1;
  float fVar2;
  undefined4 *puVar3;
  undefined4 uStack_1f8;
  int *piStack_1f4;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  int *piStack_1e4;
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  undefined4 uStack_1d8;
  int *piStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  int *piStack_1c4;
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  undefined4 uStack_1b8;
  int *piStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  int *piStack_1a4;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  int *piStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  int *piStack_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  int *piStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  int *piStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  int *piStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  int *piStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  int *piStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  int *piStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  int *piStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  int *piStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  int *piStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  int *piStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  int *piStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  int *piStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  int *piStack_dc;
  undefined4 uStack_d8;
  int *piStack_d4;
  int iStack_d0;
  
  if (DAT_00827610 != 0) {
    piVar1 = *(int **)(DAT_029131cc + 4);
    if (*(int *)(param_1 + 0x18) == 0) {
      iStack_d0 = 0x631487;
      FUN_006e3650();
    }
    else {
      iStack_d0 = 0;
      piStack_d4 = (int *)&DAT_02913204;
      uStack_d8 = 0x631480;
      FUN_006e3720();
    }
    iStack_d0 = DAT_029131cc;
    piStack_d4 = (int *)0x6314a3;
    FUN_006321b0();
    iStack_d0 = 0;
    uStack_d8 = 0x6314b3;
    piStack_d4 = piVar1;
    (**(code **)(*piVar1 + 0x170))();
    uStack_d8 = 0;
    uStack_e0 = 0x6314c0;
    piStack_dc = piVar1;
    (**(code **)(*piVar1 + 0x1ac))();
    uStack_e0 = 1;
    uStack_e4 = 0x16;
    uStack_ec = 0x6314cf;
    piStack_e8 = piVar1;
    (**(code **)(*piVar1 + 0xe4))();
    uStack_ec = 0;
    uStack_f0 = 0xe;
    uStack_f8 = 0x6314de;
    piStack_f4 = piVar1;
    (**(code **)(*piVar1 + 0xe4))();
    uStack_f8 = 0;
    uStack_fc = 7;
    uStack_104 = 0x6314ed;
    piStack_100 = piVar1;
    (**(code **)(*piVar1 + 0xe4))();
    uStack_104 = 0;
    uStack_108 = 0x89;
    uStack_110 = 0x6314ff;
    piStack_10c = piVar1;
    (**(code **)(*piVar1 + 0xe4))();
    uStack_110 = 0;
    uStack_114 = 0x1b;
    uStack_11c = 0x63150e;
    piStack_118 = piVar1;
    (**(code **)(*piVar1 + 0xe4))();
    uStack_11c = 5;
    uStack_120 = 0x13;
    uStack_128 = 0x63151d;
    piStack_124 = piVar1;
    (**(code **)(*piVar1 + 0xe4))();
    uStack_128 = 6;
    uStack_12c = 0x14;
    uStack_134 = 0x63152c;
    piStack_130 = piVar1;
    (**(code **)(*piVar1 + 0xe4))();
    uStack_134 = 0;
    uStack_138 = 0xf;
    uStack_140 = 0x63153b;
    piStack_13c = piVar1;
    (**(code **)(*piVar1 + 0xe4))();
    uStack_140 = 0x10;
    uStack_144 = 0x18;
    uStack_14c = 0x63154a;
    piStack_148 = piVar1;
    (**(code **)(*piVar1 + 0xe4))();
    uStack_14c = 5;
    uStack_150 = 0x19;
    uStack_158 = 0x631559;
    piStack_154 = piVar1;
    (**(code **)(*piVar1 + 0xe4))();
    uStack_158 = 3;
    uStack_15c = 1;
    uStack_160 = 0;
    uStack_168 = 0x63156a;
    piStack_164 = piVar1;
    (**(code **)(*piVar1 + 0x114))();
    uStack_168 = 3;
    uStack_16c = 2;
    uStack_170 = 0;
    uStack_178 = 0x63157b;
    piStack_174 = piVar1;
    (**(code **)(*piVar1 + 0x114))();
    uStack_178 = 2;
    uStack_17c = 5;
    uStack_180 = 0;
    uStack_188 = 0x63158c;
    piStack_184 = piVar1;
    (**(code **)(*piVar1 + 0x114))();
    uStack_188 = 2;
    uStack_18c = 6;
    uStack_190 = 0;
    uStack_198 = 0x63159d;
    piStack_194 = piVar1;
    (**(code **)(*piVar1 + 0x114))();
    uStack_198 = 2;
    uStack_19c = 7;
    uStack_1a0 = 0;
    uStack_1a8 = 0x6315ae;
    piStack_1a4 = piVar1;
    (**(code **)(*piVar1 + 0x114))();
    uStack_1a8 = 4;
    uStack_1ac = 4;
    uStack_1b0 = 0;
    uStack_1b8 = 0x6315bf;
    piStack_1b4 = piVar1;
    (**(code **)(*piVar1 + 0x10c))();
    uStack_1b8 = 2;
    uStack_1bc = 5;
    uStack_1c0 = 0;
    uStack_1c8 = 0x6315d0;
    piStack_1c4 = piVar1;
    (**(code **)(*piVar1 + 0x10c))();
    uStack_1c8 = 0;
    uStack_1cc = 6;
    uStack_1d0 = 0;
    uStack_1d8 = 0x6315e1;
    piStack_1d4 = piVar1;
    (**(code **)(*piVar1 + 0x10c))();
    uStack_1d8 = 5;
    uStack_1dc = 1;
    uStack_1e0 = 0;
    uStack_1e8 = 0x6315f2;
    piStack_1e4 = piVar1;
    (**(code **)(*piVar1 + 0x10c))();
    uStack_1e8 = 2;
    uStack_1ec = 2;
    uStack_1f0 = 0;
    uStack_1f8 = 0x631603;
    piStack_1f4 = piVar1;
    (**(code **)(*piVar1 + 0x10c))();
    uStack_1f8 = 0;
    (**(code **)(*piVar1 + 0x10c))(piVar1,0,3);
    uStack_1c0 = 0;
    piStack_1c4 = (int *)0x0;
    uStack_1c8 = 0;
    uStack_1cc = 0;
    piStack_1d4 = (int *)0x0;
    uStack_1d8 = 0;
    uStack_1dc = 0;
    uStack_1e0 = 0;
    uStack_1e8 = 0;
    uStack_1ec = 0;
    uStack_1f0 = 0;
    piStack_1f4 = (int *)0x0;
    uStack_1bc = 0x3f800000;
    uStack_1d0 = 0x3f800000;
    piStack_1e4 = (int *)0x3f800000;
    uStack_1f8 = 0x3f800000;
    (**(code **)(*piVar1 + 0xb0))(piVar1,0x100,&uStack_1f8);
    D3DXMatrixOrthoLH(&piStack_184,0x40000000,0x40000000,0x3f800000,0x41200000);
    (**(code **)(*piVar1 + 0xb0))(piVar1,3,&piStack_184);
    uStack_198 = 0;
    puVar3 = &uStack_1d0;
    uStack_19c = 0;
    uStack_1a0 = 0;
    piStack_1a4 = (int *)0x0;
    uStack_1ac = 0;
    uStack_1b0 = 0;
    piStack_1b4 = (int *)0x0;
    uStack_1b8 = 0;
    uStack_1c0 = 0;
    piStack_1c4 = (int *)0x0;
    uStack_1c8 = 0;
    uStack_1cc = 0;
    piStack_194 = (int *)0x3f800000;
    uStack_1a8 = 0x3f800000;
    uStack_1bc = 0x3f800000;
    uStack_1d0 = 0x3f800000;
    (**(code **)(*piVar1 + 0xb0))(piVar1,2,puVar3);
    FUN_006331d0(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x38),
                 *(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x40),
                 *(undefined4 *)(param_1 + 0x44),puVar3);
    if (*(int *)(param_1 + 0x18) == 0) {
      FUN_006321f0(DAT_029131cc);
    }
    else {
      (**(code **)(*piVar1 + 0xa8))(piVar1);
    }
    if ((*(int *)(param_1 + 0x28) != 0) &&
       (fVar2 = *(float *)(param_1 + 0x30) - 33.333336, *(float *)(param_1 + 0x30) = fVar2,
       fVar2 < 0.0)) {
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
  }
  return;
}

