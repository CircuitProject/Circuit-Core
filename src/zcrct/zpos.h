// Copyright (c) 2020 The PIVX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CIRCUIT_LEGACY_ZPOS_H
#define CIRCUIT_LEGACY_ZPOS_H

#include "stakeinput.h"
#include "txdb.h"

class CLegacyZCrctStake : public CStakeInput
{
private:
    uint32_t nChecksum;
    libzerocoin::CoinDenomination denom;
    uint256 hashSerial;

public:
    CLegacyZCrctStake() : CStakeInput(nullptr) {}

    explicit CLegacyZCrctStake(const libzerocoin::CoinSpend& spend);
    bool InitFromTxIn(const CTxIn& txin) override;
    bool IsZCRCT() const override { return true; }
    uint32_t GetChecksum() const { return nChecksum; }
    const CBlockIndex* GetIndexFrom() const override;
    CAmount GetValue() const override;
    CDataStream GetUniqueness() const override;
    bool CreateTxIn(CWallet* pwallet, CTxIn& txIn, uint256 hashTxOut = UINT256_ZERO) override { return false; /* creation disabled */}
    bool CreateTxOuts(CWallet* pwallet, std::vector<CTxOut>& vout, CAmount nTotal, const bool onlyP2PK) override { return false; /* creation disabled */}
    bool GetTxOutFrom(CTxOut& out) const override { return false; /* not available */ }
    virtual bool ContextCheck(int nHeight, uint32_t nTime) override;
};

#endif //CIRCUIT_LEGACY_ZPOS_H
