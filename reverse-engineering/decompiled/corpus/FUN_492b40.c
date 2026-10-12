/* Ghidra analysis pseudocode, not original source.
 * ev_f3574efba8633d4b71eb16d1e05784af9695c720a67aab99b2425d0d63eee0b9
 * Entry: 0x492b40; label: FUN_00492b40
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00492b40(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  float fVar2;
  undefined *puVar3;
  uint uVar4;
  char cVar5;
  undefined1 uVar6;
  int iVar7;
  undefined1 *puVar8;
  char cVar9;
  float10 fVar10;
  int iStack_c;
  float local_8;
  undefined4 uStack_4;
  
  FUN_004f4060(&param_1,&param_2);
  FUN_0055f430();
  FUN_004011e0(param_1,param_2);
  FUN_00509620(&DAT_007facf0,0x17,DAT_00802364,&LAB_00494250,1,0);
  FUN_00509760();
  FUN_0065f4f0();
  DAT_0087b540 = FUN_004f0d50();
  _DAT_0087b544 = FUN_004fc2b0("Episode_I.dat",&DAT_00924874,0);
  _DAT_0087b548 = FUN_004fc2b0("Episode_II.dat",&DAT_00924874,0);
  _DAT_0087b54c = FUN_004fc2b0("Episode_III.dat",&DAT_00924874,0);
  _DAT_0087b550 = FUN_004fc2b0("Episode_IV.dat",&DAT_00924874,0);
  _DAT_0087b554 = FUN_004fc2b0("Episode_V.dat",&DAT_00924874,0);
  _DAT_0087b558 = FUN_004fc2b0("Episode_VI.dat",&DAT_00924874,0);
  FUN_004f0d40(DAT_0087b540);
  FUN_005dabd0(1);
  FUN_005dabe0(1);
  FUN_0043c830();
  FUN_0062f970();
  FUN_00698a00(0x3f000000);
  FUN_00596530();
  FUN_0054a5e0();
  FUN_004feef0();
  FUN_00566290(2);
  FUN_0054b540(&DAT_007ff950);
  FUN_0054b580(0xffffffff);
  FUN_005476e0();
  FUN_004ca5b0();
  FUN_00547700();
  puVar3 = PTR_DAT_00802c54;
  if (DAT_0093b338 != 0) {
    PTR_DAT_00802c54 = (undefined *)0x0;
    DAT_0093d818 = 0;
    local_8 = (float)DAT_008668d0 / 10.0;
    FUN_005b2510(PTR_s_demointro_007fac08,&DAT_00924890,&DAT_00924894,_DAT_0092501c,0,local_8);
    FUN_00566290(2);
    FUN_00401870();
  }
  PTR_DAT_00802c54 = puVar3;
  if (DAT_0087b4e4 != 0) {
    FUN_0042d180(0);
  }
  if (DAT_00951ba0 == -1) {
    DAT_00951ba0 = 0;
  }
  DAT_00803784 = (uint)*(char *)(DAT_00951ba0 * 0x130 + 0xa3 + DAT_00951b78);
  DAT_0095121c = 0xffffffff;
  DAT_00951358 = 0;
  if ((DAT_00803784 == 0xffffffff) ||
     ((*(byte *)(DAT_00803784 * 0x9c + 0x7a + DAT_00951354) & 4) == 0)) {
    if ((DAT_0093b338 < 2) && ((DAT_0093b338 == 0 || (DAT_0093b2a4 == 0)))) goto LAB_00492d8c;
    DAT_0093b338 = 2;
  }
  else {
    DAT_0093b29c = 1;
  }
  DAT_0093b2a4 = 1;
LAB_00492d8c:
  DAT_0087a9c8 = 0;
  if (((DAT_007f39e4 == 0) || (DAT_00951364 == 0)) ||
     (DAT_00803784 != *(byte *)(DAT_00951364 + 0x7c))) {
    if (DAT_0093b2a4 != 0) {
      DAT_0093b29c = 0;
      DAT_0093b2a4 = 0;
    }
  }
  else {
    FUN_0047aa30();
  }
  FUN_004f3e20();
  FUN_0065f4d0();
  FUN_004fd050();
  FUN_0065f4e0();
LAB_00492de2:
  cVar5 = -1;
  if (DAT_007f39e4 != 0) {
    FUN_0042aa00(DAT_00803784);
  }
  if ((((DAT_0095121c != 0xffffffff) && (DAT_00951b7c != 0)) &&
      (((*(uint *)(DAT_00951b7c + 100) & 0x400) != 0 &&
       ((*(short *)(DAT_00803784 * 0x9c + 0x7a + DAT_00951354) != 2 && (DAT_00951364 != 0)))))) &&
     (DAT_00803784 != *(byte *)(DAT_00951364 + 0x7c))) {
    FUN_00566290(2);
  }
  FUN_0043c800();
  FUN_0046a840();
  DAT_0088ab30 = 0;
  cVar9 = cVar5;
  if (DAT_00803784 != 0xffffffff) {
    cVar9 = *(char *)(DAT_00803784 * 0x9c + 0x86 + DAT_00951354);
  }
  if (DAT_0095121c != 0xffffffff) {
    cVar5 = *(char *)(DAT_00951354 + 0x86 + DAT_0095121c * 0x9c);
  }
  if (((DAT_00803784 == 0xffffffff) || (cVar9 == -1)) || ((cVar5 != -1 && (cVar9 != cVar5)))) {
    DAT_0093b2a8 = 0;
  }
  if (DAT_0087b4d4 != '\0') {
    FUN_004ef5c0(0);
  }
  if ((DAT_00803784 == 0xffffffff) || (DAT_00803784 == DAT_0095121c)) {
    if ((DAT_00951368 != 0) && (DAT_0095df4c != 0)) {
      FUN_005aabc0(DAT_0095df4c);
    }
  }
  else if (DAT_0095df4c != 0) {
    FUN_005aab50(DAT_0095df4c);
  }
  iVar7 = FUN_005aac00(DAT_0095df4c,"FreePlay",0);
  if (iVar7 != 0) {
    fVar2 = (float)DAT_0093b2a4;
    *(ushort *)(iVar7 + 0x36) = *(ushort *)(iVar7 + 0x36) | 1;
    *(undefined1 *)(iVar7 + 0x2c) = 1;
    *(undefined1 *)(iVar7 + 0x2d) = 0;
    *(float *)(iVar7 + 0x28) = fVar2;
    *(undefined1 *)(iVar7 + 0x34) = 2;
  }
  if (DAT_007f39e4 != 0) {
    iVar7 = FUN_005aac00(DAT_0095df4c,"MissionMode",0);
    if (iVar7 != 0) {
      if ((DAT_009553d4 != 0) && (*(char *)(DAT_009553d4 + 0x1d) != '\0')) {
        *(undefined4 *)(iVar7 + 0x28) = 0x3f800000;
      }
      *(ushort *)(iVar7 + 0x36) = *(ushort *)(iVar7 + 0x36) | 1;
      *(undefined1 *)(iVar7 + 0x2c) = 1;
      *(undefined1 *)(iVar7 + 0x2d) = 0;
      *(undefined1 *)(iVar7 + 0x34) = 2;
    }
    iVar7 = FUN_005aac00(DAT_0095df4c,"ChallengeMode",0);
    if (iVar7 != 0) {
      if (DAT_00856c08 != 0) {
        *(undefined4 *)(iVar7 + 0x28) = 0x3f800000;
      }
      *(ushort *)(iVar7 + 0x36) = *(ushort *)(iVar7 + 0x36) | 1;
      *(undefined1 *)(iVar7 + 0x2c) = 1;
      *(undefined1 *)(iVar7 + 0x2d) = 0;
      *(undefined1 *)(iVar7 + 0x34) = 2;
    }
  }
  if ((((DAT_00803784 == 0xffffffff) ||
       (iVar7 = DAT_00803784 * 0x9c + DAT_00951354, *(char *)(iVar7 + 0x86) == -1)) ||
      (uVar1 = *(ushort *)(iVar7 + 0x7a), (uVar1 & 0x10) == 0)) || ((uVar1 & 4) != 0)) {
    DAT_00856c08 = 0;
    FUN_0058a8d0(0);
  }
  FUN_00547780(0);
  DAT_0093d7f0 = 0;
  DAT_0093d7f4 = 0;
  DAT_0093d7f8 = 0;
  DAT_0093d7fc = 0;
  DAT_0093d800 = 0;
  DAT_0093d804 = 0;
  DAT_0093d808 = 0;
  DAT_0093d80c = 0;
  if ((DAT_007fac20 != -1) && (DAT_00924890 == DAT_0092488c)) {
    local_8 = (float)DAT_008668d0 / 10.0;
    FUN_005b2510((&PTR_s_demointro_007fac08)[DAT_007fac20 * 3],&DAT_00924890,&DAT_00924894,
                 _DAT_0092501c,0,local_8);
  }
  DAT_007fac20 = -1;
  FUN_0048b540();
  FUN_0041ade0();
  if (DAT_0087b2dc == 0) {
    FUN_0055f470(DAT_00803784,DAT_0095121c);
  }
  if ((DAT_00802c68 == -1) || (DAT_00802c68 != DAT_00951ba0)) {
    DAT_0093d848 = DAT_00951ba0;
    DAT_0093d840 = 0;
    FUN_00560630(0);
  }
  DAT_00802c68 = -1;
  FUN_0048a4b0();
  DAT_0088a54c = 0;
  DAT_00876ccc = 0;
  FUN_00560aa0();
  FUN_0042d5f0();
  FUN_00659160();
  FUN_00408800(PTR_DAT_00802c54);
  FUN_00597250(PTR_DAT_00802c54);
  _DAT_00955b34 = 1;
  FUN_00694d50(0x3f800000,0);
  DAT_0087b71c = 0;
  FUN_00697a30(0);
  if (((DAT_00803784 != 0xffffffff) && (DAT_00803784 != DAT_0095121c)) || (DAT_00951368 != 0)) {
    FUN_0048f9b0();
  }
  FUN_00548ae0(*(undefined4 *)(PTR_DAT_00802c54 + 0x128),0,&DAT_008668cc);
  if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b88) && (DAT_008668d2 == '\0')) {
    FUN_00547a30(0);
  }
  DAT_00951368 = 0;
  DAT_008765c4 = 1;
  DAT_0093d854 = 0;
  FUN_00548fb0(&DAT_00925008,0);
  DAT_007f3b14 = 0xffffffff;
  DAT_0085ea74 = 0;
  FUN_00549430();
  do {
    if (DAT_0087658c == 0) {
      DAT_00802c6c = 1;
    }
    FUN_005a81b0(PTR_DAT_00802c54);
    if (*(int *)(PTR_DAT_00802c54 + 0x2aa4) != -1) {
      FUN_00689c80(PTR_DAT_00802c54[0x2aa4]);
    }
    FUN_00571b20(PTR_DAT_00802c54);
    if (DAT_02962034 == 0) {
      FUN_00698e70();
    }
    FUN_0055c5e0();
    FUN_005c9130(0);
    if (DAT_02962034 == 0) {
      FUN_00698e70();
    }
    if (DAT_009507a0 == -1) {
      uStack_4 = 2;
      FUN_005b1220(&uStack_4,0);
    }
    FUN_005b11b0(1);
    _DAT_0095067c = 0x3f800000;
    _DAT_00950678 = 1.0;
    FUN_0042b960();
    FUN_00694d50(0x3f800000,0);
    FUN_00548ae0(*(undefined4 *)(PTR_DAT_00802c54 + 0x128),1,&DAT_008668cc);
    if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b88) && (DAT_008668d2 == '\0')) {
      FUN_00547a30(0);
    }
    if (DAT_00803df4 != 0) {
      FUN_00653000();
      FUN_006941a0(0x10);
      FUN_00698e70();
      DAT_00803df4 = 0;
    }
    iStack_c = 0;
    FUN_005fd450();
    _DAT_00925018 = _DAT_0092501c;
    DAT_0087b528 = 0;
    _DAT_0087b52c = 0;
    DAT_0087b524 = 0;
    if (DAT_00802c6c != 0) {
      DAT_00802c5c = 0xffffffff;
      DAT_0093d84c = -1;
      DAT_00951388 = 0;
      DAT_0093d850 = 0;
    }
    DAT_00802c6c = 1;
    FUN_004f5110();
    while ((((((DAT_0087658c == 0 && (DAT_00951b80 == 0)) || (_DAT_00950780 < 1.0)) ||
             (*(int *)(DAT_0087b4d0 + 0xc) != 0)) ||
            (((DAT_0093d84c != -1 && ((DAT_00802c6c != 0 || (DAT_0093d840 != 0)))) &&
             (DAT_0087658c == 0)))) || ((DAT_007f23a4 != -1 && (DAT_0087658c == 0))))) {
      FUN_0057d230();
      iVar7 = FUN_006dd390();
      if (iVar7 == 0) break;
      FUN_006d3420();
      FUN_004f5100();
      FUN_005d8370(0,0xf);
      FUN_005d8400(0,0xf,"frmtmr");
      FUN_006579f0(_DAT_00925018);
      iVar7 = FUN_00574e20();
      uVar6 = DAT_00876577;
      if (iVar7 != 4) {
        uVar6 = DAT_008668d4._3_1_;
      }
      FUN_004badd0(uVar6);
      local_8 = _DAT_00925018;
      if (((DAT_0093d84c == -1) || (DAT_00951388 == 0)) && (DAT_00950744 == 0)) {
        if ((((DAT_00856c08 == 1) && (9 < DAT_00951244)) &&
            ((*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_00951b94 &&
             ((DAT_00855de0 == 0 && (iVar7 = FUN_0057cd80(0), iVar7 == 0)))))) &&
           (_DAT_00950780 == 0.0)) {
          FUN_0042f3a0(2,1);
        }
        FUN_00491d50(PTR_DAT_00802c54,&iStack_c);
      }
      if ((DAT_0093d84c != -1) && (DAT_00950744 == 0)) {
        _DAT_0093d844 = _DAT_0093d844 + _DAT_00925018;
      }
      if ((DAT_007f23a4 != -1) && (DAT_00950744 == 0)) {
        _DAT_00855ecc = _DAT_00925018 + _DAT_00855ecc;
      }
      _DAT_00925018 = local_8;
      iVar7 = FUN_00574e20();
      uVar6 = DAT_00876577;
      if (iVar7 != 4) {
        uVar6 = DAT_008668d4._3_1_;
      }
      FUN_00565470(uVar6);
      FUN_00548f00();
      FUN_004f3e20();
      if ((DAT_00827610 != 0) && ((DAT_00950748 == 0 || (DAT_009507a0 == 1)))) {
        if (_DAT_00950678 <= 0.0) {
          FUN_005661f0();
        }
        else {
          FUN_004927f0();
        }
      }
      if (DAT_0087b518 == 0) {
        FUN_00565700(DAT_008668d4._3_1_);
      }
      if (_DAT_00950678 != 1.0) {
        DAT_00802e30 = 0;
      }
      FUN_00565ba0();
      FUN_00565d90();
      if (DAT_0087b53c != 0) {
        DAT_0087b53c = 0;
        _DAT_0095067c = 0x3f800000;
        _DAT_00950678 = 1.0;
      }
      if (DAT_00827610 != 0) {
        FUN_004bbbf0(PTR_DAT_00802c54);
      }
      FUN_0057eec0();
      uVar4 = DAT_0087b528;
      _DAT_0087b52c = (int)DAT_0297ad74 >> 0x1f;
      iVar7 = ((_DAT_0087b52c - ((int)DAT_0087b528 >> 0x1f)) - (uint)(DAT_0297ad74 < DAT_0087b528))
              - (uint)(DAT_0297ad74 == DAT_0087b528);
      DAT_0087b528 = DAT_0297ad74;
      if ((iVar7 < 1) && (iVar7 < 0)) {
        DAT_0087b524 = 0;
      }
      else {
        DAT_0087b524 = (DAT_0297ad74 - uVar4) + -1;
      }
      if (DAT_0087b4dc < DAT_0097bb34) {
        DAT_0087b4dc = DAT_0097bb34;
      }
      _DAT_0087b4e0 = DAT_0097bb34;
      FUN_0065f4d0();
      fVar10 = (float10)FUN_004fd050();
      _DAT_00925018 = (float)fVar10;
      FUN_0065f4e0();
      if ((_DAT_00925054 < _DAT_00925018) && (DAT_00951be0 == 0)) {
        _DAT_00925018 = _DAT_00925054;
      }
      if (2 < DAT_0087b524) {
        DAT_0087b524 = 2;
      }
      if (iStack_c != 0) {
        iStack_c = 0;
      }
      if (DAT_00950744 != 0) {
        if (DAT_00950744 == 1) {
          DAT_0093b328 = DAT_0093b2a0;
        }
        DAT_00950744 = DAT_00950744 + -1;
      }
    }
    FUN_004f5110();
    FUN_0055c5e0();
    FUN_005c9130(0);
    FUN_0040aa00(0,0);
    if ((DAT_0087658c == 0) && (DAT_0092485c == 0)) {
      FUN_00566290(2);
    }
    DAT_00802e14 = 1;
    FUN_00698910();
    FUN_006dea60();
    if (*(int *)(PTR_DAT_00802c54 + 0x2aa4) != -1) {
      FUN_00689e70(PTR_DAT_00802c54[0x2aa4]);
    }
    FUN_00571b40(PTR_DAT_00802c54);
    FUN_005a8200(PTR_DAT_00802c54);
    FUN_0057cec0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ab0));
    if (DAT_02962034 == 0) {
      FUN_006987a0();
      FUN_00698e70();
    }
    FUN_0048f990(PTR_DAT_00802c54);
    if (DAT_00951b50 == 0) {
      FUN_0059fa80();
    }
    FUN_00488630();
    if ((DAT_0087658c == 0) || (DAT_0092485c != 0)) break;
    DAT_00802c6c = 0;
    DAT_00951ba4 = 0;
  } while( true );
  DAT_00802c6c = 1;
  if (DAT_0087b71c != 0) {
    FUN_0048f740(*(undefined4 *)(PTR_DAT_00802c54 + 0x120),1);
  }
  DAT_00951b7c = *(int *)(PTR_DAT_00802c54 + 0x128);
  if (DAT_007fac20 == -1) {
    DAT_0095121c = DAT_00803784;
    DAT_00951358 = DAT_00803784 * 0x9c + DAT_00951354;
  }
  else {
    DAT_0095121c = 0xffffffff;
  }
  if (DAT_00951b7c == DAT_00951b9c) {
    if (DAT_0093b0d8 == 0) {
      fVar10 = (float10)1;
    }
    else {
      fVar10 = (float10)FUN_00547ab0(DAT_0093b0d8);
    }
    local_8 = (float)fVar10;
    FUN_00547a30(local_8);
  }
  DAT_00803784 = (uint)*(char *)(DAT_00951b80 + 0xa3);
  DAT_00951ba0 = (int)*(short *)(DAT_00951b80 + 0x62);
  if ((DAT_00803784 == DAT_0095121c) && (DAT_00803784 != 0xffffffff)) {
    DAT_0087b2d4 = DAT_0087b2d4 + 1;
  }
  else {
    DAT_0087b2d4 = 0;
  }
  DAT_00951ba4 = (uint)(*(short *)(DAT_00951b80 + 0x62) != *(short *)(DAT_00951b7c + 0x62));
  if ((DAT_00803784 != DAT_0095121c) || (DAT_0087b71c != 0)) {
    if (DAT_02962034 == 0) {
      FUN_00693fd0(0);
      FUN_00548e90();
      FUN_00652ad0();
    }
    if (((DAT_00951364 == 0) || (DAT_0095121c != *(byte *)(DAT_00951364 + 0x7c))) &&
       (DAT_0093b324 != 0)) {
      if ((DAT_00951364 != 0) && (DAT_00803784 == *(byte *)(DAT_00951364 + 0x7c))) {
        DAT_00805a00 = DAT_0095121c;
      }
      DAT_0093b324 = 0;
    }
  }
  if (((DAT_00951b80 == DAT_00951b98) || ((*(uint *)(DAT_00951b80 + 100) & 0x400) != 0)) &&
     ((FUN_00483c70(PTR_DAT_00802c54), DAT_00951b80 != DAT_00951b98 && (DAT_0087a6dc != '\0')))) {
    FUN_00486c00(&DAT_0087a628);
  }
  if (DAT_00951b50 == 0) {
    if ((DAT_00803784 == 0xffffffff) || (DAT_00803784 != DAT_0095121c)) {
      if (0 < DAT_0093d818) {
        DAT_0093d81c = 2;
      }
      FUN_00414d40(8);
      DAT_00951420 = 0;
    }
    else if (DAT_0087b71c == 0) {
      FUN_00414d40(8);
      DAT_0093d81c = 1;
    }
    else {
      FUN_00414d40(8);
      DAT_0093d81c = 2;
    }
  }
  else {
    DAT_0093d516 = DAT_0087a1d8;
    DAT_0093d526 = DAT_0087a1d9;
    DAT_0093d536 = DAT_0087a1da;
    DAT_0093d546 = DAT_0087a1db;
    DAT_0093d556 = DAT_0087a1dc;
    DAT_0093d566 = DAT_0087a1dd;
    DAT_0093d576 = DAT_0087a1de;
    DAT_0093d586 = DAT_0087a1df;
    DAT_0093d81c = 2;
  }
  if (DAT_00803784 == 0xffffffff) {
    DAT_0093b29c = 0;
    DAT_0093b2a4 = 0;
  }
  else {
    if ((*(byte *)(DAT_00803784 * 0x9c + 0x7a + DAT_00951354) & 4) != 0) {
      DAT_0093b29c = 1;
      DAT_0093b2a4 = 1;
    }
    if ((DAT_0087b71c != 0) && (DAT_00803784 != DAT_0095121c)) {
      if ((DAT_00951364 != 0) && (DAT_00803784 == *(byte *)(DAT_00951364 + 0x7c))) {
        DAT_0093b29c = 0;
      }
      DAT_0093b2a4 = DAT_0093b29c;
      if (DAT_0093b29c != 0) {
        if (DAT_0093d7f0 != 0) {
          *(undefined2 *)(DAT_0093d7f0 + 0x1064) = 0xffff;
        }
        if (DAT_0093d7f4 != 0) {
          *(undefined2 *)(DAT_0093d7f4 + 0x1064) = 0xffff;
        }
        DAT_0087a9c8 = 1;
      }
    }
  }
  uVar4 = DAT_00803784;
  if ((DAT_0087a6dc != '\0') &&
     ((((DAT_00951b98 != 0 && (DAT_00951b7c == DAT_00951b98)) ||
       ((*(uint *)(DAT_00951b7c + 100) & 0x400) != 0)) ||
      ((DAT_00951b9c != 0 && (DAT_00951b7c == DAT_00951b9c)))))) {
    iVar7 = 0;
    puVar8 = &DAT_0093d516;
    do {
      if (iVar7 < 2) {
        (&DAT_0093d590)[iVar7] = (&DAT_0087a6c4)[iVar7];
        *puVar8 = (&DAT_0087a6cc)[iVar7];
      }
      else {
        (&DAT_0093d590)[iVar7] = 0xffff;
        *puVar8 = 0;
      }
      puVar8[1] = 0;
      *(undefined4 *)(puVar8 + -6) = 0;
      puVar8 = puVar8 + 0x10;
      iVar7 = iVar7 + 1;
    } while ((int)puVar8 < 0x93d596);
    if (((DAT_00951364 == 0) || (uVar4 != *(byte *)(DAT_00951364 + 0x7c))) ||
       (DAT_00951b7c == DAT_00951b88)) {
      DAT_0093d81c = 2;
    }
    else {
      DAT_0093d81c = 1;
    }
  }
  if (((DAT_00951364 != 0) && (uVar4 == *(byte *)(DAT_00951364 + 0x7c))) && (DAT_0095121c != uVar4))
  {
    if (((DAT_00951b9c != 0) && (DAT_00951b7c == DAT_00951b9c)) && (DAT_0087a6dc != '\0')) {
      FUN_0055e1b0(1,(int)DAT_0087a6c4,(int)DAT_0087a6c6);
    }
    FUN_0047aa30();
  }
  FUN_00698910();
  FUN_00595a90();
  FUN_0048b430();
  if (DAT_0087b4d4 != '\0') {
    FUN_004ef5c0(0);
  }
  FUN_00509760();
  FUN_005605b0();
  iVar7 = FUN_0055c6d0(DAT_0095121c);
  if (iVar7 != 0) {
    return 0;
  }
  goto LAB_00492de2;
}

